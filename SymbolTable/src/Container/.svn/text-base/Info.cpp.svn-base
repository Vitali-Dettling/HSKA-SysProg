/*
 * Info.cpp
 *
 *  Created on: Apr 29, 2012
 *      Author: devi1013
 */

#include "Info.h"

//Container mit value NULL als Default Wert
Info::Info( TType tokenType , long value = NULL , String* lexem = NULL)
{
	this->tokenType = tokenType;
	this->value = value;
	this->lexem = lexem;
	this->type = noType;
}

//Gibt den Wert zurück
long Info::getValueInfo()
{
	return this->value;
}

//Gibt den Token Type zurück
TType Info::getTTypeInfo()
{
	return this->tokenType;
}

//Überschreibt den alten Wert
void Info::setInfoValue( long newValue )
{
	this->value = newValue;

}

//Bekomme das String, durch dem ich das Lm erhalte
String* Info::getString()
{
	return this->lexem;
}

//Setzt den Knotentypen
void Info::setTypeInfo( TypeInfo type )
{
	this->type = type;
}

//Bekomme den typen vom Knoten
TypeInfo Info::getTypeInfo()
{
	return this->type;
}

Info::~Info()
{}
