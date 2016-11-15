/*
 * Scanner.cpp
 *
 *  Created on: 17.04.2012
 *      Author: voma1018
 */

#include "ScannerImp.h"
#include <stdlib.h>
#include "Scanner.h"

#define ENTER '\n'
#define BLANK ' '
#define GROESSE 100000

//Standard Konstruktor
ScannerImp::ScannerImp(){}

/*
 * Konstruktor
 *
 * @param char*
 * 			Die Datei, die eingelesen werden soll
 * **/
ScannerImp::ScannerImp(char* datei)
{
	init();

	this->myAutomat = new Automat(this);
	this->myBuffer = new ReadBuffer(datei);
	this->mySymTable = new SymTable(GROESSE);

	String* read = new String("read");
	mySymTable->checkLexem(read, READ);

	String* print = new String("print");
	mySymTable->checkLexem(print,PRINT);

	String* if1 = new String("if");
	mySymTable->checkLexem(if1,IF);

	String* int1 = new String("int");
	mySymTable->checkLexem(int1,INT);

	String* while1 = new String("while");
	mySymTable->checkLexem(while1,WHILE);

	String* else1 = new String("else");
	mySymTable->checkLexem(else1,ELSE);

}

// Destruktor
ScannerImp::~ScannerImp()
{
	delete myAutomat;
	delete myBuffer;
	delete mySymTable;
}
/*
 * Initialisierung von einigen Variabeln
 *
 * */
void ScannerImp::init()
{
		this->actualLine = 1;
		this->actualColomn = 1;
		this->size = 0;
		this->firstColumn = 1;
		this->firstLine = 1;
		this->commentMark = new int[2];
		this->currentType = NOPE;
		this->lastType = NOPE;
		this->comment = false;
}

/**
 * Methode welches ein Token herausfindet
 *
 * @return Token
 *
 * */
Token* ScannerImp::nextToken()
{
	char* letter;
	Token * result = NULL;

	do{
		letter = myBuffer->nextChar();	// nächsten Char bekommen
		this->lastType = this->currentType;	// Type Aktuallisierung
		this->currentType = myAutomat->giveChar(letter);	// den Char dem Automaten geben

		if(letter!= NULL) // wenn keine EOF
		{
			if(currentType != IDENTIFIER && lastType == NOPE || currentType != INTEGER && lastType == NOPE)
			{
				commentMark[0] = actualLine;
				commentMark[1] = actualColomn;
				size = 0;
			}


			if(comment) // wenn die Möglichkeit besteht einen Kommentar zu erkennen
			{
				if(*letter == ENTER )	// Zeilenumbruch
				{
					actualLine++;
					actualColomn = 1;
				}
				else	// egal welches Zeichen, voranschreiten in der Zeile
					actualColomn++;

				comment = false;
				size = 0;
			}

			else if(currentType ==NOPE && lastType == NOPE && *letter == ENTER)	// Enter ignorieren + zählen
			{
				actualLine++;
				actualColomn = 1;
				size = 0;
			}

			else if(currentType ==NOPE && lastType == NOPE && *letter == BLANK)	// Leerzeichen ignorieren + zählen
			{
				actualColomn++;
				size = 0;
			}
			else	// normaler ablauf
				size++;

		}
		else	// wenn EOF
			break;

	}while((lastType == NOPE) || (currentType!= NOPE));

	if(comment) // Kommentar der nicht abgeschhlossenwurden (EOF)
	{
		lastType = NOPE;
		return mkToken(currentType);
	}
	else{	//sonstige Token
		result = mkToken(lastType);
		return result;
	}
}

/*
 * Erstellt ein Token mit den Eigenschaften die dazugehören.
 *
 * @return Token
 *
 * **/
Token* ScannerImp::mkToken(TType type)
{
	Token* result = NULL;

	if (type != NOPE)
	{
		if(type == INTEGER || type == IDENTIFIER)
		{
			if(size <= 0  || (size-myAutomat->getBack()) < 128 ) // Zurück gehen im Buffer wenn es um die Erstellung des Token s geht
			{
				myBuffer->ungetChar(this->size );
				this->size = size-myAutomat->getBack();
			}
			else
			{
				type = ERROR;
				printf("Exception: Das Lexem überschreitet 127 Zeichen! \n" );
			}
		}
		else
		{
			//printf("%d ", size);
			myBuffer->ungetChar(myAutomat->getBack()  ); // -1 quick fix

			if(type == SIGNCOMPLEX)
			{
				actualColomn = actualColomn +3;
//				myBuffer->ungetChar(1);
			}
			else
			{
				if(type != COMMENT)
				{
					actualColomn++;
//					myBuffer->ungetChar(1);
				}
				else
				{
					actualColomn = actualColomn +2;
//					myBuffer->ungetChar(1);
				}

			}
		}

			String* lexem = new String();



		if(type == IDENTIFIER || type == INTEGER)
		{
			char* x;
			firstColumn = actualColomn;
			firstLine = actualLine;

			// das Einfügen der Zeichen in den String
			for( int i = 0 ; i < size ; i++ )
			{
				x = myBuffer->nextChar();
				lexem->add( x );
				actualColomn++;
			}


			if(lastType == INTEGER)
			{
				if (! (lexem->calcValue())) // Test, ob die Zahl berechenbar ist, also kleiner ist als der Max-Wert von LONG
				{
					result = new Token(this->firstColumn, this->firstLine, lexem, ERROR);
				}
				else
				{
					Info* key = mySymTable->checkLexem(lexem,type);
					result = new Token(this->firstColumn, this->firstLine , lexem, key);
				}
			}
			else
			{
			Info* key = mySymTable->checkLexem(lexem,type);
			result = new Token(this->firstColumn, this->firstLine , lexem, key);
			}
		}
		else
		{
			firstLine = commentMark[0];
			firstColumn =commentMark[1];
			result = new Token(this->firstColumn, this->firstLine, lexem, type);
		}
	}

	this->size = 0;
	lastType = NOPE;
	currentType = NOPE;
	this->mark = true;

	return result;
}

/*
 * Löscht das Token
 *
 * @param Token
 * 			Token welches gelöscht werden soll
 * **/
void ScannerImp::freeToken(Token* token)
{
	//if (token->getTType() != IDENTIFIER || token->getTType() != INTEGER  )
	{
		//delete token->getLexem();
	}
	delete token;
}

/*
 * Beendet einige Prozesse
 *
 * **/
void ScannerImp::stop()
{
	delete myAutomat;
}

void ScannerImp::setComment(bool status)
{
	this->comment= status;
}

/*
 * Zurückgehen in dem Buffer
 *
 * @param int
 * 			Anzahl die zurück gehen soll
 * **/
void ScannerImp::ungetChar(int count)
{
	myBuffer->ungetChar(count);
}
