/*
 * WriteBuffer.h
 *
 *  Created on: May 2, 2012
 *      Author: devi1013
 */

#ifndef WRITEBUFFER_H_
#define WRITEBUFFER_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../Scanner/src/Token.h"
#include "../../Scanner/src/TType.h"

#define SUCCESS 0
#define ERROR_CODE (-1)
#define SEGMENTATION_FAULT 22
#define WRITE_BUFFER_SIZE (256*1024)
#define SAFTY_OUTPUT 512
#define TEMP_BUFFER 1024



class WriteBuffer
{

private:

	//Allokation der Buffer Teile
	char* outputBuffer;
	char* tempBuf;

	//Zum auslesen des Files
	int outFile;
	int bufSize;
	ssize_t outFileByte;



public:
	WriteBuffer( );
	virtual ~WriteBuffer();


	//Öffnet das file und bei Fehler gibt er -1 zurück, ansonsten 0
	int openFile( );

	//Befüllt das File, wenn der outputBuffer voll ist
	void writeFiel( Token* token );

	//Gibt die gewünschte Ausgabe aus
	size_t whichOutput( Token* token );

	//Augabe des Buffers
	void printBuffer();

};

#endif /* WRITEBUFFER_H_ */
