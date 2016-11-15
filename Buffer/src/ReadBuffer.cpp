/*
 * ReadReadBuffer.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: devi1013
 */

#include <stdio.h>
#include <unistd.h>

#include "ReadBuffer.h"

//Damit es ein eigenständiges prozess ist und nicht von ReadBuffer abhängig ist
extern "C"
{
	//Was der thread wirklich tut
	void * threadFillUnusedBuffer(void * param)
	{
		ReadBuffer * thread;
		thread = (ReadBuffer*) param;

		printf("Thread gestartet \n");

		//Überprüft welcher Buffer gerade nicht verwendet wird
		if(thread->threadBufferWritter == FIRST_BUFFER)
		{
			thread->threadBufferWritter = SECOND_BUFFER;
			printf("Lesen: Wechsel 1 auf 2\n");
		}
		else if(thread->threadBufferWritter == SECOND_BUFFER)
		{
			thread->threadBufferWritter = THIRD_BUFFER;
			printf("Lesen: Wechsel 2 auf 3\n");
		}
		else if(thread->threadBufferWritter == THIRD_BUFFER)
		{
			thread->threadBufferWritter = FIRST_BUFFER;
			printf("Lesen: Wechsel 3 auf 1\n");
		}

		//Füllt den unbenutzen Buffer und beended dann den Thread
		thread->readFile();

		pthread_mutex_unlock(&thread->mutex);

		printf("Thread ist tot \n");
		pthread_exit(NULL);
		};
}

//Wechselt den Buffer
void ReadBuffer::previuseBuffer()
{
	if( whichBuffer == FIRST_BUFFER )
	{
		whichBuffer = THIRD_BUFFER;
		printf("UngetChar: Wechsel 1 auf 3 \n");

	}
	else if(whichBuffer == SECOND_BUFFER )
	{
		whichBuffer = FIRST_BUFFER;
		printf("UngetChar: Wechsel 2 auf 1\n");
	}
	else if(whichBuffer == THIRD_BUFFER )
	{
		whichBuffer = SECOND_BUFFER;
		printf("UngetChar: Wechsel 3 auf 2\n");
	}
	else
	{
		whichBuffer = ERROR_CODE;
		printf("UngetChar: nene SO NICHT!!");
	}
}

void ReadBuffer::nextBuffer(){
	if( whichBuffer == FIRST_BUFFER)
		{
			whichBuffer = SECOND_BUFFER;
			printf("NextChar: Wechsel 1 auf 2 \n");

		}
		else if(whichBuffer == SECOND_BUFFER )
		{
			whichBuffer = THIRD_BUFFER;
			printf("NextChar: Wechsel 2 auf 3\n");
		}
		else if(whichBuffer == THIRD_BUFFER )
		{
			whichBuffer = FIRST_BUFFER;
			printf("NextChar: Wechsel 3 auf 1\n");
		}
		else
		{
			whichBuffer = ERROR_CODE;
			printf("NextChar: nene SO NICHT!!");
		}

}


//Konstruktor dem der Pfad übergeben wurden ist, wo das File liegt
ReadBuffer::ReadBuffer( const char* fileName )
{

	try
	{
		//Wenn das file nicht geöffnet werden kann, dann wird auch das Objekt nicht initialisiert
		if(openFile( fileName ) == ERROR_CODE)
		{
			throw "Exception: Buffer Objekt wurde nicht initialisiert\n";
		}

		//Reservierung von Speicherplatz
		posix_memalign( ( void** ) &firstBuffer , BLOCK_BUFFER_SIZE , READ_BUFFER_SIZE );
		posix_memalign( ( void** ) &secondBuffer , BLOCK_BUFFER_SIZE , READ_BUFFER_SIZE );
		posix_memalign( ( void** ) &thirdBuffer , BLOCK_BUFFER_SIZE , READ_BUFFER_SIZE );

		//Beginnt mit dem ersten Buffer
		whichBuffer = FIRST_BUFFER;
		setUnget = false;

		//File-Ende ist nach dem letzten char
		fileEnd = lseek(file, 0, SEEK_END);
		//Setzt den filePos auf den Anfang des Files
		filePos	= lseek(file, 0, SEEK_SET);
		//Setzt den countUntilEnd auf den Anfang
		countUntilEnd = filePos;

		//Überprüft ob das File leer ist
		isFileEmpty = false;
		if( fileEnd == filePos ){ isFileEmpty = true; }

		//Mutex
		pthread_mutex_init(&(this->mutex),NULL);

		read( file, firstBuffer , READ_BUFFER_SIZE );
		read( file, secondBuffer , READ_BUFFER_SIZE  );

		this->threadBufferWritter = SECOND_BUFFER;



	}catch(char const* ex)
	{
		printf(ex);
	}

}

//Öffnet das file und bei Fehler gibt er -1 zurück, ansonsten 0
int ReadBuffer::openFile(const char* fileName )
{
	try
	{
		//File nicht verfügbar
		file = open( fileName, O_DIRECT | O_RDONLY| O_SYNC );
		if( file == ERROR_CODE )
		{
			file = open( fileName, O_RDONLY );
			if(file == ERROR_CODE)
			{
				throw "Exception: File ist nicht verfügbar.\n";
			}
		}

	}
	catch(char const* ex)
	{
		printf(ex);
		if(EINVAL == SEGMENTATION_FAULT)
		{
			printf("--> Exception: Sie haben keine lese Berechtigung.\n");
		}
		return ERROR_CODE;
	}

	return SUCCESS;

}


//Lade den Inhalt einen Feiles in ein Buffer
//Der Inhalt wird in 2 Bufferteilen unterteilt
void ReadBuffer::readFile()
{
	try
	{

		//Lade den Inhlt in das jeweilige Buffer
		if(threadBufferWritter == FIRST_BUFFER)
		{

			fileByte = read( file, firstBuffer , READ_BUFFER_SIZE );
		}
		else if( threadBufferWritter == SECOND_BUFFER)
		{
			fileByte = read( file, secondBuffer , READ_BUFFER_SIZE );
		}
		else if(threadBufferWritter == THIRD_BUFFER)
		{
			fileByte = read( file, thirdBuffer , READ_BUFFER_SIZE );
		}
		if( fileByte == ERROR_CODE)
		{
			throw "Exception: Das lesen der Datei-Inhaltes ist fehlgeschlagen. \n";
		}

	}
	catch(char const* ex)
	{
		printf(ex);
	}
}


//Startet den Thread, damit dieser den dritten Buffer befüllen kann
void ReadBuffer::startThread()
{

	if (!pthread_mutex_lock(&mutex))
	{
		pthread_create( &(this->thread), NULL, threadFillUnusedBuffer,  (void*) this );
	}

}


//Gibt das nächste Character Reference zurück
//Entwerder vom einem Buffer oder dem zweiten
char* ReadBuffer::nextChar()
{
	try
	{   //EOF wurde überschritten
		if(filePos > fileEnd)
		{
			throw "Exception: EOF wurde überschritten.\n";
		}
	}catch(char const * ex)
	{
		printf(ex);
		return NULL;
	}

	//Überprüft ob das Ende des Files erreicht wurden ist
	if( countUntilEnd == fileEnd || isFileEmpty )
	{
		return NULL;
	}


	if(this->filePos == READ_BUFFER_SIZE)
	{
		//Wechselt den Buffer
		nextBuffer();
		filePos = 0;
	}

	if( this->whichBuffer == this->threadBufferWritter)
	{

		//Einlesen des neuen Buffers, fals NICHT in der zwischenzeit zurückgegangen ist
		if( setUnget == false )
		{
			pthread_join(thread, NULL);
			startThread();
		}

		//Setzt die bool Valiarbe zurück, damit ein Buffer beim nächsten mal befüllt werden kann
		setUnget = false;

	}

	//Erster Buffer oder zweiter Buffer oder dritter Buffer
	//Gibt den Inhalt des Buffer aus und zählt dann eins hoch
	if( whichBuffer == FIRST_BUFFER )
	{
		countUntilEnd++;
		return &firstBuffer[filePos++];
	}
	else if(whichBuffer == SECOND_BUFFER)
	{
		countUntilEnd++;
		return &secondBuffer[filePos++];
	}
	else if(whichBuffer == THIRD_BUFFER)
	{
		countUntilEnd++;
		return &thirdBuffer[filePos++];
	}
}


//Buffer Zurückgehen
void ReadBuffer::ungetChar(int unget)
{
	try
	{
		//Fals das File leer ist.
		if( isFileEmpty )
		{
			throw "Exception: File ist leer. Es ist nicht möglich Zeichen zurückzugehen.\n";
		}
		//ungültiger Parameterübergabe
		if( unget <= 0 )
		{
			throw "Exception: Ungültiger 'unget' Übergabe.\n";
		}
		//'unget' ist größer als die beiden Bufffer zusammen
		if( unget >= (2 * READ_BUFFER_SIZE) )
		{
			throw "Exception: 'unget' überschreitet die Größe der beiden Buffers. \n";
		}

		//Wächsel zum anderen Buffer
		if( filePos < unget)
		{
			//Wechselt den Buffer
			previuseBuffer();

			//Setzt die bool Variable, damit ein Buffer nicht zwei mal befüllt wird.
			setUnget = true;

			//Berechnet die neue Position von fileEnd
			countUntilEnd = countUntilEnd - unget;
			unget = unget -  filePos ;
			filePos = READ_BUFFER_SIZE;
			filePos = filePos - unget;
		}
		else//Wenn 'unget' innerhalb eines Buffers ist
		{
			countUntilEnd = countUntilEnd - unget;
			filePos = filePos - unget;
		}

		//Überprüft ob filePos nicht außerhalb der Buffergröße ist.
		if( filePos < 0 && filePos > (READ_BUFFER_SIZE -1) )
		{
			throw "Exception: Buffer interner Fehler mit filePos ist außerhalb der Buffergöße.\n";
		}


	}catch(char const * ex)
	{
		printf(ex);
	}
}

ReadBuffer::~ReadBuffer(void)
{
	//Schliesen des Files
	close(file);
	delete[] this->firstBuffer;
	delete[] this->secondBuffer;
	delete[] this->thirdBuffer;

	pthread_mutex_destroy(&this->mutex);
}
