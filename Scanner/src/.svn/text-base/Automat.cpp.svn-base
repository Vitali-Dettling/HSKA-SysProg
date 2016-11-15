/*
 * Automat.cpp
 *
 *  Created on: 07.04.2012
 *      Author: voma1018
 */

#include "Automat.h"
#include "states/StateStart.h"
#include "states/StateSignStar1.h"
#include "states/StateSignStar2.h"
#include "Token.h"
#include <stdlib.h>

#define BLANK ' '
#define ENTER '\n'

Automat::Automat(){}

Automat::Automat(Scanner* scanner)
{
	this->myScanner = scanner;
	this->currentState = StateStart::stateNow();
	this->back = 0;
}

Automat::~Automat(){}

/**
 *
 * Getter Methode um Back zu bekommen
 *
 * */
int Automat::getBack()
{
	return this->back;
}

/**
 *	Diese Methode übernimmt die Kontrolle über den kompletten Automat-
 *	verlauf.
 *
 *	@ param char*
 *			Der Buchstabe der übergeben wird und womit gearbeitet wird.
 *
 * */
TType Automat::giveChar(char * letter)
{
	if (letter != NULL)	// EOF
	{	// Aktuallisierung von Endstate !!
		if (currentState->isEndState  )
		{
			back = 0;
			lastFinalState = currentState;
		}
		// Wenn enter oder leerzeichen am anfang des prozesses kommt
		if ((*letter == BLANK && currentState == StateStart::stateNow() )|| (*letter == ENTER && currentState == StateStart::stateNow() ))
		{
			return NOPE;
		} // wenn was anderes kommt
		else
		{	//wenn es im kommentar ist (back soll nicht hochgezählt werden)
			if(currentState == StateSignStar1::stateNow() || currentState == StateSignStar2::stateNow())
			{
				myScanner->setComment(true);
				currentState = currentState->work(letter);
			}// normales arbeiten
			else
			{
				back++;
				currentState = currentState->work(letter); // nächsten Buchstaben weitergeben!!+
			}
		}
	}
	else
	{	// EOF und es ist im Kommentar drin!!
		if (currentState == StateSignStar1::stateNow() || currentState == StateSignStar2::stateNow())
		{
			myScanner->setComment(true);
			currentState = StateStart::stateNow();
			return ERROR;
		}//sonstlicher EOF!
		else
		{
			this->back = 0;
			return NOPE;			// eig NULL zurück da fertig ist !!
		}
	}

	return currentState->getType();
}

void Automat::setBack(int number)
{
	this-> back = number;
}
