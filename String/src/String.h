/*
 * IString.h
 *
 *  Created on: Apr 1, 2012
 *      Author: devi1013
 */

#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include <math.h>
#include <string.h>

#define START_VALUE 128
#define UNSIGNED_LONG_MAX  4294967295
#define ERROR_CODE (-1)

class String
{
private:

	//Dynamischer Array
	char* name;

	//Zähl Variablen
	unsigned int size;
	unsigned int arraySize;
	unsigned long value;

	//Einfügen funktionit nicht mehr, wenn das Flag gesetzt worden ist
	bool FlagAdd;

public:
	//Defaut Konstruktor
	String( void );

	//Konstruktor für char Arraies
	String(char _name[]);

	//Kopierkonstruktor
	String(const String& _other);

	virtual ~String(void);

//Gibt die länge des Stringes zurück
unsigned int length() const;

//Fürgt dem String ein weiteres Zeichen an
void add(char * addChar);

//Berechnet denn Wert der Stringes
bool calcValue();

//Bekommt NULL zurück, wenn es keinen Wert gibt
long getValue() const;

//operator[] wurde überladen
char& operator[](unsigned int index);

//Gibt die Anfangsadresse vom String zurück
const char* getString();

//Check if the String of the opject is the same
const bool compare( String* str );

};


#endif /* STRING_H_ */
