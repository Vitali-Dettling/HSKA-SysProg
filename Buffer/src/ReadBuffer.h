/*
 * ReadReadBuffer.h
 *
 *  Created on: Apr 8, 2012
 *      Author: devi1013
 */

#ifndef READBuffer_H_
#define READBuffer_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>

#define SUCCESS 0
#define ERROR_CODE (-1)
#define SEGMENTATION_FAULT 22
#define READ_BUFFER_SIZE 512
#define BLOCK_BUFFER_SIZE 4096
#define FIRST_BUFFER 1
#define SECOND_BUFFER 2
#define THIRD_BUFFER 3



class ReadBuffer
{
private:

		//Allokation der Buffer Teile
		char* firstBuffer;
		char* secondBuffer;
		char* thirdBuffer;

		//Threads ließt den dritten Buffer ein, wärend das Programm weiterläuft
		pthread_t thread;


		//Zum auslesen des Files
		int file;
		off_t fileEnd;
		int filePos;
		off_t countUntilEnd;
		ssize_t fileByte;

		//Sicherheitsabfragen
		bool isFileEmpty;
		bool setUnget;
;

		//Startet den Thread, damit dieser den dritten Buffer befüllen kann
		void startThread();

public:

	pthread_mutex_t mutex;

	//Benötigt der Thread um den dritten Buffer zu füllen
	int threadBufferWritter;
	int whichBuffer;

	//Konstruktor dem der Pfad übergeben wurden ist, wo das File liegt
	ReadBuffer(const char* fileName);
	virtual~ReadBuffer();

	//Öffnet das file und bei Fehler gibt er -1 zurück, ansonsten 0
	int openFile(const char* fileName );

	//Lade den Inhalt einen Feiles in ein Buffer
	void readFile();

	//Gibt das nächste Character Reference zurück
	char* nextChar();

	//Buffer Zurückgehen
	void ungetChar(int unget);

	//Wechselt den Buffer
	void previuseBuffer();
	void nextBuffer();

};

#endif /* READBuffer_H_ */
