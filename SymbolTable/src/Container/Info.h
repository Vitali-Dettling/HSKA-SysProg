/*
 * Info.h
 *
 *  Created on: Apr 29, 2012
 *      Author: devi1013
 */

#ifndef INFO_H_
#define INFO_H_

#include "../../../Scanner/src/TType.h"
#include "../../../String/src/IString.h"
#include "../../../Parser/src/TypeInfo.h"
#include "stdlib.h"

class Info
{

private:

	TType tokenType;
	long value;
	String* lexem;
	TypeInfo type;

public:

	//Container
	Info(  TType tokenType , long value , String* lexem );
	virtual ~Info();

	//Gibt den Wert zurück
	long getValueInfo();

	//Gibt den Token Type zurück
	TType getTTypeInfo();

	//Bekomme das String, durch dem ich das Lm erhalte
	String* getString();

	//Setzt den Knotentypen
	void setTypeInfo( TypeInfo type );

	//Bekomme den typen vom Knoten
	TypeInfo getTypeInfo();

	//Überschreibt den alten Wert
	void setInfoValue( long newValue );

};

#endif /* INFO_H_ */
