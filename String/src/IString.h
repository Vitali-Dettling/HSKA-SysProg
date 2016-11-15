/*
 * IString.h
 *
 *  Created on: Apr 11, 2012
 *      Author: devi1013
 */

#ifndef ISTRING_H_
#define ISTRING_H_

#include "String.h"

class IString
{

public:

	/*
	 *@return Gibt die Länge des Stringes zurück.
	 */
	virtual unsigned int length() const
	{
		return this->length();
	}

	/*
	 * Fügt dem String eine weitere char hinzu.
	 * Die Zeichen sollten nicht größer als 128 Zeichen groß sein,
	 *
	 *@param Pointer von dem einzufügendem character.
	 *       Die character werden hintereinander eingefügt.
	 *
	 *@return Gibt true zurück, wenn das lerxen nicht zu groß geworden ist.
	 */
	virtual void add(char * addChar)
	{
		return this->add( addChar );
	}

	/*
	 * Der umgerechnete Wert wird als long Type zurückgegeben.
	 *
	 *@return NULL wenn der String keinen Wert hat.
	 *		  Ansonsten wird der Berechnete Wert zurückgegeben
	 */
	virtual long getValue() const
	{
		return this->getValue();
	}

	/*
	 * Berechnet den Wert des Übergebenen chars
	 * Dieser muss aus Zahlen bestehen.
	 * Der Zahlenwert entspricht dem Wert der Character
	 * in aneinanderhängenden Reichenfolge.
	 * Am Ende sollte immer '\0' stehen als Abschlusstake.
	 * Sollte einmal nach dem Befüllen des Stringes ausgeführ werden,
	 * damit der Wert intern abgespeichert wird.
	 * Mit der getValue() Methode kann der Wert, dann immer abgegriffen werden.
	 *
	 * @return bool Fals die Rechnung geklappt hat
	 * 				Der Wert darf nicht größer sein als der unsigned long
	 */
	bool calcValue()
	{
		this->calcValue();
	}

};

#endif /* ISTRING_H_ */
