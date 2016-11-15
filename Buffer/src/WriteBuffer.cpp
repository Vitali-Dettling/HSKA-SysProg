/*
 * WriteBuffer.cpp
 *
 *  Created on: May 2, 2012
 *      Author: devi1013
 */

#include "WriteBuffer.h"

//Erzeigt ein neues File in dem die Auasgabe getätigt wird
WriteBuffer::WriteBuffer( )
{

		try
		{
			//Wenn das file nicht geöffnet werden kann, dann wird auch das Objekt nicht initialisiert
			if(openFile( ) == ERROR_CODE)
			{
				throw "Exception: Buffer Objekt wurde nicht korrekt initialisiert\n";
			}

			//Reservierung von Speicherplatz
			this->outputBuffer  = new char[ WRITE_BUFFER_SIZE ];
			this->tempBuf =  new char[ TEMP_BUFFER ];

			this->bufSize = 0;

		}catch(char const* ex)
		{
			printf(ex);
		}

}

//Öffnet das file und bei Fehler gibt er -1 zurück, ansonsten 0
int WriteBuffer::openFile( )
{
	try
	{
		//Erzeugen eines Files mit Lese und Schreibrechten
		outFile = open( "Token_output.txt", O_CREAT , S_IREAD|S_IWRITE );
		if( outFile == ERROR_CODE )
		{
			throw "Exception: Es konnte kein File angelgt werden.\n";
		}
		else
		{
			//File nicht verfügbar
			outFile = open( "Token_output.txt", O_DIRECT | O_WRONLY   );
			if( outFile == ERROR_CODE )
			{
				//Erzeugt ein File ohne O_DIRECT
				outFile = open( "Token_output.txt", O_WRONLY );
				if(outFile == ERROR_CODE)
				{
					throw "--> Exception: File ist nicht verfügbar.\n";
				}
			}
		}
	}
	catch(char const* ex)
	{
		printf(ex);
		if(EINVAL == SEGMENTATION_FAULT)
		{
			printf("--> Exception: Sie haben keine Schreibe Berechtigung.\n");
		}
		return ERROR_CODE;
	}

	return SUCCESS;

}

	//Befüllt das File, wenn der outputBuffer voll ist
	void WriteBuffer::writeFiel( Token* token )
	{

		if( token != NULL )
		{
			try
			{
				size_t _writtenSize = whichOutput( token );

				//Überprüft ob der zwischen Buffer korrekt befüllt wurde.
				if( _writtenSize == ERROR_CODE )
				{
					throw "Der Zwischenbuffer hat den großen Buffer nicht befüllt.\n";
				}
				else
				{
					//Beschreibt den großen Buffer bevor er ausgegeben wird
					for( int i = 0 ; i < _writtenSize ; i++ )
					{
						outputBuffer[ this->bufSize++ ]  = tempBuf[ i ];
					}
				}
			}
			catch( const char* ex )
			{
				printf(ex);
			}

		}
		else//Ausgabe, wenn es keine Token mehr gibt
		{
			printBuffer();
		}

		//Gibt den Buffer aus sobald er voll ist
		if( this->bufSize >= ( WRITE_BUFFER_SIZE - SAFTY_OUTPUT ) )
		{
			printBuffer();
		}
	}

	//Befüllt das File, wenn der outputBuffer voll ist
	size_t  WriteBuffer::whichOutput( Token* token )
	{

	size_t _writtenSize = ERROR_CODE;

	//Initialisiert denn zwischenbuffer mit leerzeichen, damit es keine falschen Ausgaben gibt
	memset( tempBuf , ' ' , TEMP_BUFFER );

	//Beschreibt den Zwischenbuffer mit den jeweiligen Werten um sie danach in den großen Buffer zu befüllen
	//Falls es keinen Info Kontainer gibt
	if( token->getKey() == NULL )
	{
			_writtenSize = snprintf( tempBuf , TEMP_BUFFER , "Token: %s column: %d row: %d\n" ,TTYPE_NAMES[ token->getTType() ]  ,token->getColumn() , token->getRow() );
	}
	else//Je nach Token type wird die befüll option ausgewählt
	{
			switch( token->getKey()->getTTypeInfo() )
			{
				case INTEGER:
					_writtenSize = snprintf( tempBuf , TEMP_BUFFER , "Token: %s column: %d row: %d Value: %d\n" ,TTYPE_NAMES[ token->getKey()->getTTypeInfo() ]  ,token->getColumn() , token->getRow() , token->getKey()->getValueInfo() );
					break;

				default:
					_writtenSize = snprintf( tempBuf , TEMP_BUFFER , "Token: %s column: %d row: %d Lexem: %s\n" ,TTYPE_NAMES[ token->getKey()->getTTypeInfo() ]  ,token->getColumn() , token->getRow() , token->getLexem()->getString() );
			}
		}

		return _writtenSize;
	}

	//Augabe des Buffers
	void  WriteBuffer::printBuffer()
	{
		//Füllt den Buffer mit den leerzeichen, wenn er noch nicht voll ist
		if( this->bufSize !=  WRITE_BUFFER_SIZE )
		{
			for( int i = ( WRITE_BUFFER_SIZE - 1 ) ; i >=  this->bufSize ; i-- )
			{
				outputBuffer[ i ]  = ' ';
			}

			//Damit bei der zwischenausgabe ein zeilenumbruch gemacht wird
			outputBuffer[ ( WRITE_BUFFER_SIZE - 1 ) ]  = '\n';
		}

		//Test ob der Bufferinhalt ins File geschreiben werden konnte
		try
		{
			this->outFileByte = write( outFile, outputBuffer, WRITE_BUFFER_SIZE);

			if( this->outFileByte == ERROR_CODE )
			{
				throw "Buffer Inhalt konnte nicht ins File geschrieben werden.\n";
			}

			//Damit der Buffer wieder vom neuem gefüllt werden kann
			this->bufSize = 0;
		}
		catch( const char* ex )
		{
			printf(ex);
		}

	}

	WriteBuffer::~WriteBuffer()
	{
		//Schliesen des Files
		close(outFile);

		//Löscht die allokierten Buffer
		delete[] outputBuffer;
		delete[] tempBuf;
	}
