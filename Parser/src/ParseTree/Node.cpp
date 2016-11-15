/*
 * Node.cpp
 *
 *  Created on: May 28, 2012
 *      Author: devi1013
 */

#include "Node.h"

//Maximale Anzahl an Knoten
static unsigned int countNodes = 0;
//Damit die makren im code immer eindeutig sind
static unsigned int cMark = (-1);
//Damit jeder Knoten die MakeCodeOutput kennt
static MakeCodeOutput* code;

//Konstruktor für den root knoten
Node::Node( MakeCodeOutput* _code )
{
	code = _code;
	this->notTerminale = ROOT;

	//Erzeugt speicherplatz für die Zeiger
	this->ArrayLength = INIT_LENGTH;
	this->ptrCurrent = 0;
	this->filledArray = 0;

	//Einer der beiden wird übernohmen, der andere bleibt auf seinem Defaultwert
	this->type = noType;

	//Das erte mal wird der Vector Array aud eine Stelle initialisiert und dann immer um ADD_VECTOR_SIZE erweitert
	resizeVector();

	//Zählt die Knoten mit um zu wissen wie viele Knoten zu löschen sind
	countNodes++;
}

//Konstruktor für den Root Knoten, Variable ist defaultmäßig auf EPSELON
Node::Node( NotTerminal nt = EPSELON , Info* info = NULL)
{
		//Erzeugt speicherplatz für die Zeiger
		this->ArrayLength = INIT_LENGTH;
		this->ptrCurrent = 0;
		this->filledArray = 0;

		//Das erte mal wird der Vector Array aud eine Stelle initialisiert und dann immer um ADD_VECTOR_SIZE erweitert
		resizeVector();

		//Einer der beiden wird übernohmen, der andere bleibt auf seinem Defaultwert
		this->notTerminale = nt;
		this->info = info;
		this->type = noType;

		//Für eindeutige marken
		this->markeUp = new char[ MARKE_BUFFER ];

		//Zählt die Knoten mit um zu wissen wie viele Knoten zu löschen sind
		countNodes++;
}

//Löscht den Baum
Node::~Node(  )
{
	delete[] this->vector;
	delete[] this->markeUp;

}

void Node::treeDelete()
{
	int count = 0;

	if(this->vector[count] != NULL)
	{
		while(this->ArrayLength > count)
		{
			this->vector[count]->treeDelete();
			delete this->vector[count];
			this->vector[count] = NULL;
			count++;
		}
	}
}

//Einfügen eines Knoten
Node* Node::add( NotTerminal nt = EPSELON , Info* info = NULL )
{
		this->vector[ this->filledArray ] =  new Node( nt , info );
		return this->vector[ this->filledArray++ ];
}

//Der vector wird immer um 2 vergrößert
void Node::resizeVector()
{
	//Geht nur ein einzigesmal rein
	if( this->ArrayLength  == INIT_LENGTH )
	{
		//Erzeugt ein Array das Node Zeiger beinhaltet
		this->vector =  new Node*[ START_VECTOR_SIZE ];
		cleanArray();
		this->ArrayLength = START_VECTOR_SIZE;
	}
	else
	{
		//Das Array wird um ADD_VECTOR_SIZE erweitert
		Node** tmp = new Node*[ ADD_VECTOR_SIZE ];
		cleanArray();

		//Koppiert den alten Vector in den neuen
		for( int i  = 0 ; i < this->ArrayLength ; i++ )
		{
			tmp[ i ] = this->vector[ i ];
		}
		//Löschen des alten Vectors
		delete[] this->vector;

		//Umhängen des Vectors
		this->vector = tmp;

		//Die Array größe wird neu eingefügt
		this->ArrayLength = this->ArrayLength + ADD_VECTOR_SIZE;
	}
}

//setzt alle Vectoren auf NULL
void Node::cleanArray()
{
	for(int i = 0 ; i< this->ArrayLength ; i++)
	{
		this->vector[i] = NULL;
	}
}

//Gibt die Knoten von links nach rechts zurück
Node* Node::next()
{
	if( this->ptrCurrent < this->filledArray )
	{
		return this->vector[ this->ptrCurrent++ ];
	}
	else//Überprüft auch gleichzeitig ob es weitere Knoten gibt, wenn nicht wirtd NULL zurückgegeben
	{
		this->ptrCurrent = 0;
		return NULL;
	}
}

//Bricht die Kontrollierung des Baums ab und schmeißt eine Exception
void Node::error()
{
	printf( "Exception: Die Symantik ist Fehlerhaft.\n" );

	this->treeDelete();//Löscht den Baum
	exit( ERROR_CODE );//Beendet das Programm
}

//----------------------------------------------------------------------- typeCheck -----------------------------------------------------------------------------------------------------------------

//Semantische Analyse
void Node::typeCheck()
{
	switch ( this->notTerminale )
	{
		case ROOT: this->typeCheckROOT(); break;

		case PROG:this->typeCheckPROG(); break;

		case DECLS_1: this->typeCheckDECLS_1(); break;
		case DECLS_E: this->typeCheckDECLS_E(); break;

		case DECL: this->typeCheckDECL(); break;

		case ARRAY_1: this->typeCheckARRAY_1(); break;
		case ARRAY_E: this->typeCheckARRAY_E(); break;

		case STATEMENTS_1: this->typeCheckSTATEMENTS_1(); break;
		case STATEMENTS_E: this->typeCheckSTATEMENTS_E(); break;

		case STATEMENT_1: this->typeCheckSTATEMENT_1(); break;
		case STATEMENT_2: this->typeCheckSTATEMENT_2(); break;
		case STATEMENT_3: this->typeCheckSTATEMENT_3(); break;
		case STATEMENT_4: this->typeCheckSTATEMENT_4(); break;
		case STATEMENT_5: this->typeCheckSTATEMENT_5(); break;
		case STATEMENT_6: this->typeCheckSTATEMENT_6(); break;

		case EXP: this->typeCheckEXP(); break;

		case EXP2_1: this->typeCheckEXP_2_1(); break;
		case EXP2_2: this->typeCheckEXP_2_2(); break;
		case EXP2_3: this->typeCheckEXP_2_3(); break;
		case EXP2_4: this->typeCheckEXP_2_4(); break;
		case EXP2_5: this->typeCheckEXP_2_5(); break;

		case INDEX_1: this->typeCheckINDEX_1(); break;
		case INDEX_E: this->typeCheckINDEX_E(); break;

		case OP_EXP_1: this->typeCheckOP_EXP_1(); break;
		case OP_EXP_E: this->typeCheckOP_EXP_E(); break;
		case OP_PLUS: this->typeCheckOP_PLUS(); break;
		case OP_MINUS: this->typeCheckOP_MINUS(); break;
		case OP_MULT: this->typeCheckOP_MULT(); break;
		case OP_LESS: this->typeCheckOP_LESS(); break;
		case OP_GREATER: this->typeCheckOP_GREATER(); break;
		case OP_EQUAL: this->typeCheckOP_EQUAL(); break;
		case OP_UNEQUAL: this->typeCheckOP_UNEQUAL(); break;
		case OP_AND: this->typeCheckOP_AND();  break;
		case OP_DIV: this->typeCheckOP_DIV(); break;

		default:printf("EXCEPOTION: Kein passender NotTerminal -> TypeCheck\n");
		}
}

void Node::typeCheckROOT()
{
	this->vector[0]->typeCheck();//PROG


}

void Node::typeCheckPROG()//PROG ::= DECLS STATEMENTS
{
	this->vector[0]->typeCheck();//DECLS
	this->vector[1]->typeCheck();//STATEMENTS
	this->type = noType;
}

void Node::typeCheckARRAY_1()//ARRAY::=[integer]
{
	//Überprüft ob das Array wirklich einen gültigen Wert hat
	if( this->vector[0]->info->getValueInfo() > 0 )
	{
		this->type= arrayType ;
		return;
	}
		this->type= errorType;
}

void Node::typeCheckARRAY_E()//ARRAY ::= EPSELON
{
	this->type = noType;
}

void Node::typeCheckDECL()//DECL::= int ARRAY identifier
{
	this->vector[0]->typeCheck();//ARRAY

	TypeInfo _type = this->vector[1]->info->getTypeInfo();

	//Überprüfung des Indentifires
	if ( _type  != noType )
	{//(getType(identifier) != noType)
		this->type = errorType;
		error();//identifier existiert bereits
	}
	else if ( this->vector[0]->type  == errorType)
	{//ARRAY.type==errorType
		this->type = errorType;
	}
	else
	{
		this->type = noType;

		if ( this->vector[0]->type == arrayType )
		{//(ARRAY.type == arrayType
			this->vector[1]->info->setTypeInfo( intArrayType );
			//store( this->info->getTTypeInfo() , intArrayType);
		}
		else
		{
			this->vector[1]->info->setTypeInfo( intType );
			//store( this->info->getTTypeInfo() , intType);
		}
	}


}

void Node::typeCheckDECLS_1()//DECLS ::= DECL ; DECLS
{
	this->vector[0]->typeCheck();//DECL
	this->vector[1]->typeCheck();//DECLS

    this->type = noType;
}

void Node::typeCheckDECLS_E()//STATEMENTS ::= EPSELON
{
	this->type = noType;
}

void Node::typeCheckSTATEMENTS_1()//STATEMENTS ::= STATEMENT ; STATEMENTS
{
	this->vector[0]->typeCheck();//STATEMENT
	this->vector[1]->typeCheck();//STATEMENTS
	this->type = noType;
}


void Node::typeCheckSTATEMENTS_E()//STATEMENTS ::= EPSELON
{
	this->type = noType;
}

void Node::typeCheckSTATEMENT_1()//STATEMENT ::= identifier INDEX = EXP
{
		this->vector[2]->typeCheck();//EXP
		this->vector[1]->typeCheck();//INDEX


		if ( this->vector[0]->info->getTypeInfo() == noType )
		{ //getType(identifier) == noType)
			this->type = errorType;
			error();//identifier ist nicht definiert
		}
		else if ( this->vector[2]->type == intType && ( ( this->vector[0]->info->getTypeInfo() == intType && this->vector[1]->type == noType) || ( this->vector[0]->info->getTypeInfo() == intArrayType && this->vector[1]->type == arrayType ) ) )
		{			   	   //( EXP.type == intType && ( ( getType(identifier) 				   == intType & INDEX.type == noType) 			   || ( getType(identifier) 			     == intArrayType && INDEX.type 			 == arrayType)) )

			this->type = noType;
		}
		else
		{
			error();//type ist nicht kompatibel
			this->type = errorType;
		}

}

void Node::typeCheckSTATEMENT_2()//STATEMENT ::= print( EXP )
{
		this->vector[0]->typeCheck();//EXP
		this->type = noType;
}

void Node::typeCheckSTATEMENT_3()//STATEMENT ::= read( identifier INDEX)
{
		this->vector[1]->typeCheck();//INDEX

		if ( this->vector[0]->info->getTypeInfo() == noType)
		{
			this->type = errorType;
			error();//Identifire ist nicht definiert
		}
		else    if ( ( ( this->vector[0]->info->getTypeInfo() == intType ) && this->vector[1]->type == noType) ||( ( this->vector[0]->info->getTypeInfo() == intArrayType) && this->vector[1]->type == arrayType ) )
		{//else if ( ( (getType(identifier) 			      == intType ) && INDEX.type == noType) 					||( (getType(identifier) 			  == intArrayType) &&INDEX.type    				  == arrayType ) )
			this->type = noType;
		}
		else
		{
			error();//Der Type ist nicht Komplet
			this->type = errorType;
		}
}

void Node::typeCheckSTATEMENT_4()//STATEMENT ::= { STATEMENTS } )
{
		this->vector[0]->typeCheck();//STATEMENTS
		this->type = noType;
}

void Node::typeCheckSTATEMENT_5()//STATEMENT ::= if ( EXP ) STATEMENT else STATEMENT )
{
		this->vector[0]->typeCheck();//EXP
		this->vector[1]->typeCheck();//STATEMENT
		this->vector[2]->typeCheck();//STATEMENT

		if ( this->vector[0]->type == errorType)
		{ //(EXP.type == errorType)
			this->type = errorType;
		}
		else
		{
			this->type = noType;
		}

}
void Node::typeCheckSTATEMENT_6()//STATEMENT ::= while (EXP ) STATEMENT
{
		this->vector[0]->typeCheck();//EXP
		this->vector[1]->typeCheck();//STATEMENT

		if (this->vector[0]->type == errorType)
		{//(EXP.type == errorType)
			this->type = errorType;
		}
		else
		{
			this->type = noType;
		}

}

void Node::typeCheckEXP()//EXP ::= EXP2 OP_EXP
{
		this->vector[0]->typeCheck();//EXP2
		this->vector[1]->typeCheck();//OP_EXP

		if( this->vector[1]->type == noType )
		{//OP_EXP.type == noType
		 this->type = this->vector[0]->type;
		 //this->type = EXP2->type ;
		}
		else if( this->vector[0]->type != this->vector[1]->type )
		{//EXP2.type != OP_EXP.type
			this->type = errorType;
		}
		else
		{
			this->type = this->vector[0]->type;
			//this->type = EXP2.type
		}
}

void Node::typeCheckEXP_2_1()//EXP2 ::= ( EXP )
{
	this->vector[0]->typeCheck();//EXP

	this->type = this->vector[0]->type;
	//this->type = EXP.type ;
}

void Node::typeCheckEXP_2_2()//EXP2 ::= identifier INDEX
{
	this->vector[1]->typeCheck();//INDEX

	TypeInfo _type = this->vector[0]->info->getTypeInfo();

	if( _type == noType )
	{//identifier.type == noType
		this->type = errorType;
		error();//identifier wurde nicht definiert
	}
	else if( _type  == intType         && this->vector[1]->type == noType )
	{//(getType(identifier) == intType && INDEX.type == noType
		this->type = _type;
		//this->type = getType(identifier);
	}
	else if( _type == intArrayType 		   && this->vector[1]->type == arrayType )
	{//getType(identifier) == intArrayType && INDEX.type == arrayType
		this->type = intType;
	}
	else
	{
		this->type = errorType;
		error();//Es ist kein primitiver Datentype
	}
}

void Node::typeCheckEXP_2_3()//EXP2 ::= integer
{
	this->type = intType ;
}

void Node::typeCheckEXP_2_4()//EXP2 ::= - EXP2
{
	this->vector[0]->typeCheck();//EXP2

	this->type = this->vector[0]->type;
	//this->type     = EXP2.type
}
void Node::typeCheckEXP_2_5()//EXP2 ::= ! EXP2
{
	this->vector[0]->typeCheck();//EXP2

	if ( this->vector[0]->type != intType )
	{//EXP2.type != intType
		this->type = errorType;
	}
	else
	{
		this->type = intType;
	}
}

void Node::typeCheckINDEX_1()//INDEX ::= [ EXP ]
{
	this->vector[0]->typeCheck();//EXP

	if( this->vector[0]->type == errorType )
	{//EXP.type == errorType
		this->type = errorType;
	}
	else
	{
		this->type = arrayType;
	}
}

void Node::typeCheckINDEX_E()//INDEX ::= EPSELON
{
	this->type = noType ;
}

void Node::typeCheckOP_EXP_1()//OP_EXP ::= OP EXP
{
	this->vector[0]->typeCheck();//OP
	this->vector[1]->typeCheck();//EXP

	this->type = this->vector[1]->type;
	//this->type 	 = EXP.type
}

void Node::typeCheckOP_EXP_E()///OP_EXP ::= EPSELON
{
	this->type = noType;
}

void Node::typeCheckOP_PLUS(){ this->type = opPlus; }//OP ::= +
void Node::typeCheckOP_MINUS(){ this->type = opMinus; }//OP ::= -
void Node::typeCheckOP_MULT(){ this->type = opMult; }//OP ::= *
void Node::typeCheckOP_DIV(){ this->type = opDIV; }//OP ::= /
void Node::typeCheckOP_LESS(){ this->type = opLess; }//(OP ::= <
void Node::typeCheckOP_GREATER(){ this->type = opGreater; }//OP ::= >
void Node::typeCheckOP_EQUAL(){ this->type = opEqual; }//OP ::= =
void Node::typeCheckOP_UNEQUAL(){ this->type = opUnEqual; }//(OP ::= <!>
void Node::typeCheckOP_AND(){ this->type = opAnd; }//OP ::= &

//---------------------------------------------------------------------------- makeCode ---------------------------------------------------------------------------------------------------------

//Schreibt den überprüften Code in eine Text Datei
void Node::makeCode()
{
	switch( this->notTerminale )
	{
		case ROOT: makeCodeROOT(); break;

		case PROG: makeCodePROG(); break;

		case DECLS_1: makeCodeDECLS_1(); break;
		case DECLS_E: makeCodeDECLS_E(); break;

		case DECL: makeCodeDECL(); break;

		case ARRAY_1: makeCodeARRAY_1(); break;
		case ARRAY_E: makeCodeARRAY_E(); break;

		case STATEMENTS_1: makeCodeSTATEMENTS_1(); break;
		case STATEMENTS_E: makeCodeSTATEMENTS_E(); break;

		case STATEMENT_1: makeCodeSTATEMENT_1(); break;
		case STATEMENT_2: makeCodeSTATEMENT_2(); break;
		case STATEMENT_3: makeCodeSTATEMENT_3(); break;
		case STATEMENT_4: makeCodeSTATEMENT_4(); break;
		case STATEMENT_5: makeCodeSTATEMENT_5(); break;
		case STATEMENT_6: makeCodeSTATEMENT_6(); break;

		case EXP: makeCodeEXP(); break;

		case EXP2_1: makeCodeEXP_2_1(); break;
		case EXP2_2: makeCodeEXP_2_2(); break;
		case EXP2_3: makeCodeEXP_2_3(); break;
		case EXP2_4: makeCodeEXP_2_4(); break;
		case EXP2_5: makeCodeEXP_2_5(); break;

		case INDEX_1: makeCodeINDEX_1(); break;
		case INDEX_E: makeCodeINDEX_E(); break;

		case OP_EXP_1: makeCodeOP_EXP_1(); break;
		case OP_EXP_E: makeCodeOP_EXP_E(); break;

		case OP_PLUS: makeCodeOP_PLUS(); break;
		case OP_MINUS: makeCodeOP_MINUS(); break;
		case OP_MULT: makeCodeOP_MULT(); break;
		case OP_DIV: makeCodeOP_DIV(); break;
		case OP_LESS: makeCodeOP_LESS(); break;
		case OP_GREATER: makeCodeOP_GREATER(); break;
		case OP_EQUAL: makeCodeOP_EQUAL(); break;
		case OP_UNEQUAL: makeCodeOP_UNEQUAL(); break;
		case OP_AND: makeCodeOP_AND(); break;
		default: printf("EXCEPOTION: Kein passender NotTerminal -> makeCodeOutput");
		}
}

void Node::makeCodeROOT()//PROG
{
	this->vector[0]->makeCode();
	//Letzte ausgabe
//	code->printBuffer(NULL);     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	code->startThread(code->threadWriteBuffer);

	pthread_mutex_lock(&code->theMutex);

	//void* status;
	pthread_join(code->threadWriteBuffer, NULL);  // &status
}

void Node::makeCodePROG()// PROG ::= DECLS STATEMENTS)
{
	this->vector[0]->makeCode();//DECLS
	this->vector[1]->makeCode();//STATEMENTS

	code->code("\nSTP" , 4 );
	//code << " STP"
}

void Node::makeCodeDECLS_1()// (DECLS ::= DECL ; DECLS )
{
	this->vector[0]->makeCode();//DECL
	this->vector[1]->makeCode();//DECLS
}

void Node::makeCodeDECLS_E()//(DECLS ::= EPSELON)
{/*Stimmt schon*/}

void Node::makeCodeDECL()//(DECL::= int ARRAY identifier)
{
	code->code( "\nDS $" , 5 , this->vector[1]->info->getString() );
	//code << “ DS ” << “$” << getLexem(indentifier);

	this->vector[ 0 ]->makeCode();//ARRAY
}

void Node::makeCodeARRAY_1()//ARRAY ::= [ integer ]
{
	code->code( " " , 1 , this->vector[0]->info->getString() );
	//code << getValue(integer);
}
void Node::makeCodeARRAY_E()//ARRAY ::= EPSELON
{
	code->code(" 1" , 2);
		//code << 1;
}

void Node::makeCodeSTATEMENTS_1()//STATEMENTS ::= STATEMENT ; STATEMENTS
{
	this->vector[0]->makeCode();//STATEMENT
	this->vector[1]->makeCode();//STATEMENTS
}

void Node::makeCodeSTATEMENTS_E()//STATEMENTS ::= EPSELON
{
	code->code("\nNOP", 4 );
	//code << “ NOP ”;
}

void Node::makeCodeSTATEMENT_1()//STATEMENT ::= identifier INDEX = EXP
{
	this->vector[2]->makeCode();//EXP

	code->code( "\nLA $", 5  , this->vector[0]->info->getString());
	//code << “ LA ” << “$” << getLexem(identifier) ;

	this->vector[1]->makeCode();//INDEX

	code->code( "\nSTR", 4 );
	//code << “ STR ”;
}

void Node::makeCodeSTATEMENT_2()//STATEMENT ::= print( EXP )
{
	this->vector[0]->makeCode();//EXP

	code->code( "\nPRI" ,4 );
	//code << “ PRI ”;
}

void Node::makeCodeSTATEMENT_3()//STATEMENT ::= read( identifier INDEX )
{
	code->code( "\nREA", 4 );
	//code << “ REA ”;

	code->code( "\nLA $", 5 , this->vector[0]->info->getString() );
	//code << “ LA ” << “$” << getLexem(identifier);

	this->vector[1]->makeCode();//INDEX

	code->code( "\nSTR" ,4 );
	//code << “ STR ”;
}

void Node::makeCodeSTATEMENT_4()//STATEMENT ::= { STATEMENTS }
{
	this->vector[0]->makeCode();//STATEMENTS
}

void Node::makeCodeSTATEMENT_5()//STATEMENT ::= if (EXP ) STATEMENT else STATEMENT
{
	this->vector[0]->makeCode();//EXP

	//Erzeugen eines unverkenbaren marke Zeichen
	createMarke();

	code->code( "\nJIN #" , 6 , this->marke1 );
	//code << “ JIN ” << “#” << marke1; // marke1 ist neu

	this->vector[1]->makeCode();//STATEMENT

	code->code( "\nJMP #" , 6 , this->marke2 );
	//code << “ JMP ” << “#” << marke2; // marke2 ist neu

	code->code( "\n#" , 2 , this->marke1 );
	code->code( " NOP" , 4 );
	//code << “#” << marke1 << “ NOP ”;

	this->vector[2]->makeCode();//STATEMENT

	code->code( "\n#" , 2 , this->marke2 );
	code->code( " NOP" , 4 );
	//code << “#” << marke2 << “ NOP ”;}

}

void Node::makeCodeSTATEMENT_6()//STATEMENT ::= while (EXP ) STATEMENT
{
	//Erzeugen zwei unverkenbaren marken
	createMarke();

	code->code( "\n#" , 2 , this->marke1 );
	code->code( " NOP" , 4 );
	//code << “#” << marke1 << “ NOP ”; // marke1 ist neu makeCode(EXP);

	this->vector[0]->makeCode();//EXP

	code->code( "\nJIN #" , 6 , this->marke2 );
	//ode << “ JIN ” << “#” << marke2; // marke2 ist neu

	this->vector[1]->makeCode();//STATEMENT

	code->code( "\nJMP #" , 6 , this->marke1 );
	//code << “ JMP ” << “#” << marke1;

	code->code( "\n#" , 2 , this->marke2 );
	code->code( " NOP" , 4);
	//code << “#” << marke2 << “ NOP ”;
}

//Erzeugen immer zwei unverkennbare marken
void Node::createMarke()
{
	if( cMark >= MARK_OVERFLOW )
	{
		cMark = -1;
	}

	//Befüllt den zwischenbuffer mit Leerzeichen damit des keine unnötigen Zeichen mehr beinhaltet
	memset( this->markeUp , '\0' , MARKE_BUFFER );
	//Wandelt die Integerzahl in ein char um
	sprintf( this->markeUp , "m%d", ++cMark);
	//Verpackt die char Zahl in die String Klasse
	this->marke1 = new String( this->markeUp );

	//Erzeugt die zweite Marke
	memset( this->markeUp , '\0' , MARKE_BUFFER );
	sprintf( this->markeUp , "m%d", ++cMark);
	this->marke2 = new String( this->markeUp );
}

void Node::makeCodeEXP()//EXP ::= EXP2 OP_EXP
{
	if( this->vector[1]->type == noType )
	{//if (OP_EXP.type == noType )

		this->vector[0]->makeCode();//EXP2

	}
	else if( this->vector[1]->vector[0]->type == opGreater )
	{//else if (OP_EXP.OP.type == opGreater)

		this->vector[1]->makeCode();//OP_EXP
		this->vector[0]->makeCode();//EXP2

		code->code( "\nLES" , 4 );
		//code << “LES”;
	}
	else if( this->vector[1]->vector[0]->type == opUnEqual )
	{//else if (OP_EXP.OP.type == opUnEqual)

		this->vector[0]->makeCode();//EXP2
		this->vector[1]->makeCode();//OP_EXP

		code->code( "\nNOT" , 4 );
		//code << “NOT”;
	}
	else
	{

		this->vector[0]->makeCode();//EXP2
		this->vector[1]->makeCode();//OP_EXP
	}
}

void Node::makeCodeEXP_2_1()//EXP2 ::= ( EXP )
{
	this->vector[0]->makeCode();//EXP
}

void Node::makeCodeEXP_2_2()//EXP2 ::= identifier INDEX)
{
	code->code( "\nLA $", 5 , this->vector[0]->info->getString() );
	//code << “ LA ” << “$” << getLexem(identifier) ;

	this->vector[1]->makeCode();//INDEX

	code->code( "\nLV" , 3 );
	//code << “ LV ”;
}

void Node::makeCodeEXP_2_3()//EXP2 ::= integer )
{
	code->code( "\nLC " , 4 , this->vector[0]->info->getString() );
	//code << “ LC ” << getValue(integer);
}
void Node::makeCodeEXP_2_4()//EXP2 ::= - EXP2
{
	code->code( "\nLC 0", 5 );
	//code << “ LC ” << 0

	this->vector[0]->makeCode();//EXP2

	code->code( "\nSUB" , 4 );
	//code << “ SUB ”;
}

void Node::makeCodeEXP_2_5()//EXP2 ::= ! EXP2
{
	this->vector[0]->makeCode();//EXP2

	code->code( "\nNOT" , 4 );
	//code << “ NOT ”;
}

void Node::makeCodeINDEX_1()//INDEX ::= [ EXP ]
{
	this->vector[0]->makeCode();//EXP

	code->code( "\nADD" , 4 );
	//code << “ ADD ”;
}

void Node::makeCodeINDEX_E()
{/*Stimmt schon*/}

void Node::makeCodeOP_EXP_1()//OP_EXP ::= OP EXP
{
	this->vector[ 1 ]->makeCode();//EXP
	this->vector[ 0 ]->makeCode();//OP
}
void Node::makeCodeOP_EXP_E()//OP_EXP ::= EPSELON
{/*Stimmt schon*/}

void Node::makeCodeOP_PLUS()//OP ::= +
{
	code->code( "\nADD" , 4 );
	//code << “ADD”;
}
void Node::makeCodeOP_MINUS()//OP ::= -
{
	code->code( "\nSUB" , 4 );
	//code << “SUB”;
}
void Node::makeCodeOP_MULT()//OP ::= *
{
	code->code( "\nMUL" , 4 );
	//code << “MUL”;
}
void Node::makeCodeOP_DIV()//OP ::= /
{
	code->code( "\nDIV" , 4 );
	//code << “DIV”;
}
void Node::makeCodeOP_LESS()//OP ::= <
{
	code->code( "\nLES" , 4 );
	//code << “LES”;
}
void Node::makeCodeOP_GREATER()//OP ::= >
{} //siehe EXP ::= EXP2 OP_EXP

void Node::makeCodeOP_EQUAL()//OP ::= =
{
	code->code( "\nEQU" , 4 );
	//code << “EQU”;
}
void Node::makeCodeOP_UNEQUAL()//OP ::= <!>
{
	code->code( "\nEQU" , 4 );
	//code << “EQU”;

} //siehe EXP ::= EXP2 OP_EXP
void Node::makeCodeOP_AND()//OP ::= &
{
	code->code( "\nAND" , 4 );
	//code << “AND”;
}
