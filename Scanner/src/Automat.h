/*
 * Automat.h
 *
 *  Created on: 07.04.2012
 *      Author: voma1018
 */

#ifndef AUTOMAT_H_
#define AUTOMAT_H_

#include "states/State.h"
#include "Scanner.h"

class Automat
{
	Scanner* myScanner;					// Mein Scanner
	State* lastFinalState;				// letzter finaler Zustand
	State* currentState;				// aktueller Zustand
	int back; 							// Anzahl, die man über dem letzten EndState drüber ist

public:

	Automat();							// Standart Konstruktor

	/*
	 * Konstruktor
	 *
	 * @param scanner
	 * 		Scannerinterfaceeee
	 * */
	Automat(Scanner* scanner);			// Konstruktor

	// Destruktor
	virtual ~Automat();
	int getBack();
	void setBack(int);

	/**
	 *	Diese Methode übernimmt die Kontrolle über den kompletten Automat-
	 *	verlauf.
	 *
	 *	@ param char*
	 *			Der Buchstabe der übergeben wird und womit gearbeitet wird.
	 *
	 *	@return TType
	 *			Token Type welcher erkannt wurde
	 *
	 * */
	TType giveChar(char * letter);

};

#endif /* AUTOMAT_H_ */
