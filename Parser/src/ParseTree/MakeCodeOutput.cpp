/*
 * makeCodeOutput.cpp
 *
 *  Created on: Jul 9, 2012
 *      Author: devi1013
 */

#include "MakeCodeOutput.h"


////Augabe des Buffers
static void *printBuffer(void* arg)
{
	MakeCodeOutput *mco  = (MakeCodeOutput*) arg ;

	char* writeBufferMemory = mco->getWriteBuffer();


	//Test ob der Bufferinhalt ins File geschreiben werden konnte
	try
	{

		//für tests
		//		mco->changeBuffer();  // Gedanke Überschreibung

		//Befüllt den Restbuffer mich leerzeichen -> -1 um das letzte \n ebenfalls wegzubekommen
		for( int i = mco->getBufSize() ; i < WRITE_BUFFER_SIZE ; i++ )
		{
			writeBufferMemory[ i ] = ' ';

			// this->outputBuffer2[i] = ' ';   //evtl noch nich sicha

		}

		//File-Ende ist nach dem letzten char
		lseek(mco->getOutFile() , 0, SEEK_END);

		//Übeprüft und schreibt gleichzeitig den gesammten Buffer in das File
		if( write( mco->getOutFile(), writeBufferMemory, WRITE_BUFFER_SIZE) == ERROR_CODE )
		{
			throw "Buffer Inhalt konnte nicht ins File geschrieben werden.\n";
		}

		//Damit der Buffer wieder vom neuem gefüllt werden kann
//		bufSize = 0;
		mco->setBufSize(0);

		printf("ich bin drin!! \n");




	}
	catch( const char* ex )
	{
		printf(ex);
	}

	pthread_mutex_unlock(&mco->theMutex);

	// Terminiert den aufgerufenen Thread
			pthread_exit(NULL);


}



//Erstellt eine Datei in dem der Assemplerkode gespeichert wird
MakeCodeOutput::MakeCodeOutput()
{
	try
	{
		// Init ein angeletes Mutex
		pthread_mutex_init(&theMutex,NULL);

//		pthread_mutex_lock(&theMutex);
//
//		if( ! pthread_mutex_lock(&theMutex))
//		{
//			printf("hi");
//
//		}


		//Erzeugen eines Files mit Lese und Schreibrechten
		outFile = open( "codeMade.code", O_CREAT , S_IREAD|S_IWRITE );
		if( outFile == ERROR_CODE )
		{
			throw "Exception: Es konnte kein File angelgt werden.\n";
		}
		else
		{
			//File nicht verfügbar
			outFile = open( "codeMade.code", O_DIRECT | O_WRONLY   );
			if( outFile == ERROR_CODE )
			{
				//Erzeugt ein File ohne O_DIRECT
				outFile = open( "codeMade.code", O_WRONLY );
				if(outFile == ERROR_CODE)
				{
					throw "--> Exception: File ist nicht verfügbar.\n";
				}
			}
		}

//		pthread_mutex_unlock(&theMutex);

		//Initialisierung der benötigten Variablen
		this->fillBuffer = new char[ WRITE_BUFFER_SIZE ];
		this->writeBuffer = new char[WRITE_BUFFER_SIZE];
		this->again = true;
		this->bufSize = 0;

	}
	catch(char const* ex)
	{
		printf(ex);
	}
}

//Speichert in einen Buffer um danach in einem Rutsch alles auszugeben
void MakeCodeOutput::code( const char outStr[] , int size , String* lexem )
{
	//Einmal nach jedem ausschreiben des Buffers
	if( this->again )
	{	//Befüllt den zwischenbuffer mit Leerzeichen damit des keine unötigen Zeichen mehr beinhaltet
		memset( this->fillBuffer , '\0' , WRITE_BUFFER_SIZE );
		this->again = false;
	}

	//Zählt die größe der Zeichenkette mit dem '\n'
	this->bufSize += size;

	//Schreibt in den Zwischenspeicher und gibt die Länge des geschriebenen Wortes zurück
	strcat( this->fillBuffer, outStr );
	//Wenn es ein Lexem gibt, dann wird es hinten angeheftet
	if( lexem != NULL )
	{
		strcat( this->fillBuffer , lexem->getString() );
		this->bufSize = this->bufSize + lexem->length();

	}

	//Gibt den Buffer nach SAFTY_OUTPUT maligen befüllen aus
	if( this->bufSize >= ( WRITE_BUFFER_SIZE - SAFTY_OUTPUT )  )
	{


		// Semathore kommen hier rein bei der

		startThread(this->threadWriteBuffer);
		//Buffer kann neu befüllt werden
		this->again = true;


	}
}

// Tausch von den Buffern
void MakeCodeOutput::changeBuffer()
{
	char* help;

	help = fillBuffer;
	fillBuffer = writeBuffer;
	writeBuffer = help;



}

//Destruktor
MakeCodeOutput::~MakeCodeOutput()
	{
		close( this->outFile );
		delete[] this->fillBuffer;
		delete[] this->writeBuffer;
	}

unsigned long int MakeCodeOutput::getBufSize()
	{
		return this->bufSize;
	}

int MakeCodeOutput::getOutFile()
	{
		return this->outFile;
	}

char* MakeCodeOutput::getFillBuffer()
	{
		return this->fillBuffer;
	}

char* MakeCodeOutput::getWriteBuffer()
	{
		return this->writeBuffer;
	}

void MakeCodeOutput::setBufSize(int size)
	{
		this->bufSize = size;
	}



/**
 * Methode die den Thread startet.
 *
 * */
void MakeCodeOutput::startThread(pthread_t th)
{
	if(!pthread_mutex_lock(&theMutex)){

	changeBuffer();		//evtl  Gedanke überschreibung
	this->status = pthread_create(&th,NULL,printBuffer,(void*)this);

	}

//	// statisch vereinbarter Mutex
//	this->mutex = PTHREAD_MUTEX_INITIALIZER;

	//sperren mutex

	// Mutex freigeben
//	pthread_mutex_unlock(&theMutex);
//
//	// wie lock bloß wird nicht gewartet
//	pthread_mutex_trylock(&theMutex);



}
