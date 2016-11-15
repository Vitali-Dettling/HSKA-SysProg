/*
 * String.cpp
 *
 *  Created on: Apr 1, 2012
 *      Author: dev1013
 */

#include "String.h"

//Defaut Konstruktor
String::String()
{
	this->size = 0;
	this->arraySize = START_VALUE;
	//+1 wegen dem endtak vom String '\0'
	this->name = new char[ START_VALUE +1 ];
	//Initialisiert denn String mit Endzeichen
	memset( this->name , '\0' , START_VALUE );
	this->value = NULL;
	this->FlagAdd = true;
}

//Konstruktor für char Arraies
String::String(char _name[])
{
	this->FlagAdd = true;
	unsigned int _size = 0;
	this->value = NULL;

	//Zählt die Länge der Arraies
	do {/*...*/}
	while(_name[_size++] != '\0');

	this->size = _size -1;
	this->name = new char[_size];//New size of the array
	//Koppiert das Array
	for(int i = 0 ; i < _size ; i++)
	{ this->name[i] = _name[i]; }
}

//Kopierkonstruktor
String::String(const String& _other)
{
	this->FlagAdd = true;
	this->value = NULL;
	this->size = _other.size;
	this->name = new char[size];//New size of the array
	//Copy array
	for(unsigned int i = 0 ; i < _other.size ; i++)
	{
		this->name[i] = _other.name[i];
	}

}

//Gibt die länge des Stringes zurück
unsigned int String::length() const
{
	return this->size;
}

//Fürgt dem String ein weiteres Zeichen ein
void String::add(char* addChar)
{

	//FlageAdd ist solange ture, solange es die START_VALUE = 128 nicht überschreitet
	if( this->FlagAdd == true )
	{
		//Das Lexem darf 128 Zeichen nicht überschreiten,
		//da im WriteBuffer die Sicherheitsasgabe bei START_VALUE = 128 Zeichen geschieht
		if(this->size  == this->arraySize )
		{
			printf("Exception: Das Lexem ist zu groß.\n");
			//Das Einfügen ist nicht mehr erlaubt
			this->FlagAdd = false;
		}
		else
		{
			//Zeichen wird eingefügt
			this->name[ this->size ] = *addChar;
			this->size++;
		}
	}
}

//Berechnet denn Wert der Stringes
//Value wird NULL wenn es kein Wet ist
bool String::calcValue()
{
	//Ob es ausrechnen soll oder nicht
	bool calc = true;
	try
	{
		//Fals der String leer ist
		if(this->size == 0)
		{
			throw "Exception: Der String ist leer.\n";
		}

		//Prüft ob der übergebene String nur Zahlen beinhaltet
		for(int i = 0 ; i < this->size ; i++)
		{
			if( this->name[ i ] < '0' || this->name[ i ] > '9')
			{
				calc = false;
				throw "Der String bestand nicht nur aus Zahlen.\n";
				break;
			}
		}
		}
	catch(char const* ex)
	{
		printf(ex);
	}

	//Berechnet den Wert, wenn er nur aus Zahlen bestand.
	if( calc == true )
	{
		for( int i = 0 ; i < this->size ; i++ )
		{
			this->value += ( this->name[ this->size -1 -i ] - '0' ) * pow(10,i);

			if( this->value > UNSIGNED_LONG_MAX )
			{
				printf("Exception: Der long Wert wurde überschritten.\n");
				this->value = ERROR_CODE;
				break;
			}
		}

		//Fals die größe des unsigned long überschrieten wird
		if( this->value == ERROR_CODE )
		{
			return false;
		}

		return true;
	}
}

//Gibt die Anfangsadresse vom String zurück
const char* String::getString()
{
	return this->name;
}

//Gibt den Wert zurück
long String::getValue() const
{
  return this->value;
}

//Gibt den Inhalt vom Index zurück
char& String::operator[](unsigned int index)
{
	try
	{
		if( index > this->size || index < 0)
		{
			throw index;
		}
		else
		{
			return name[ index ];
		}
	}
	catch(const int * ex)
	{
		printf("Exception: Der Indexzugrif ist größer oder kleiner als die Stringlänge: Index: %d -> Stringlänge: %d.\n", ex , this->size);
	}
}

//Check if the String of the opject is the same
const bool String::compare( String* str )
{
	//Lenght different than the string can be correct
	if( this->size != str->size )
	{
		return false;
	}

	//Check the sttring
	for( int i = 0 ; i < this->size ; i++  )
	{
		if( this->name[i] != str->name[i] )
		{
			return false;
		}
	}

	return true;

}

String::~String()
{
	delete[] this->name;
}
