/*
 * IBuffer.h
 *
 *  Created on: Apr 8, 2012
 *      Author: devi1013
 */

#ifndef IBUFFER_H_
#define IBUFFER_H_

#include "ReadBuffer.h"
#include "WriteBuffer.h"
#include "../../Scanner/src/Token.h"

#define SUCCESS 0
#define ERROR_CODE (-1)
#define SEGMENTATION_FAULT 22


class IBuffer
{

public:

	/*
	 * Gibt das nächste Zeichen raus und setzt den Zeiger auf das nächste Zeichen.
	 * Bis das EOF eirreicht ist. Das EOF wird durch '\0' representiert.
	 * Wenn das File leer ist, gibt es das EOF zurück.
	 */
	virtual char* nextChar()
	{
		this->nextChar();
	}

	/*
	 * Geht die Anzahl Zeichen zurück, die durch 'unget' Parameter eingestellt wurden ist.
	 * @param "unget" Wie viele Zeichen sollen zurückgehen.
	 * 		   Kleiner 1 'unget' sind nicht erlaubt.
	 */
	virtual void ungetChar( int unget )
	{
		this->ungetChar( unget );
	}

	/*
	 * Befüllt einen internen Buffer, sobald er voll ist wird der Inhalt des Buffers in ein File geschrieben.
	 * Die Parameter die ausgeben werden sollen befinden sich im tokel Objekt.
	 *@param Beinhaltet die Parameter die ins File geschrieben werden.
	 */
	void writeFiel( Token* token )
	{
		this->writeFiel( token  );
	}


};


#endif /* IBUFFER_H_ */
