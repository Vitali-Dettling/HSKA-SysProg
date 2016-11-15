/*
 * makeCodeOutput.h
 *
 *  Created on: Jul 9, 2012
 *      Author: devi1013
 */

#ifndef MAKECODEOUTPUT_H_
#define MAKECODEOUTPUT_H_

#include "Node.h"
#include <pthread.h>

#define SUCCESS 0
#define ERROR_CODE (-1)
#define WRITE_BUFFER_SIZE  (64*2048)
#define SAFTY_OUTPUT  256

class Node;

class MakeCodeOutput
{
private:

	//Reference auf das aktuelle Knoten Objekt
	Node* node;

	//Zeiger auf das File
	int outFile;

	//Buffer zum zwischenspeichern und ausgeben
	//char* outputBuffer; //Alter Buffer
	unsigned long bufSize;
	bool again;

	//Buffer zum zwischenspeichern und ausgeben
	char* fillBuffer;
	char* writeBuffer;


//	pthread_mutex_t mutex;

	int status;

public:
	pthread_mutex_t theMutex;
	pthread_t threadWriteBuffer;


	MakeCodeOutput();
	virtual ~MakeCodeOutput();

	//Speichert in einen Buffer um danach in einem Rutsch alles auszugeben
	void code( const char outStr[] , int size = 0 , String* lexem = NULL );

	void changeBuffer();

	unsigned long int getBufSize();
	int getOutFile();
	char* getFillBuffer();
	char* getWriteBuffer();
	void setBufSize(int);

	void startThread(pthread_t);



};

#endif /* MAKECODEOUTPUT_H_ */
