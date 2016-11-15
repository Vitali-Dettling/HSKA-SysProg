/*
 * ISymTable.h
 *
 *  Created on: Apr 11, 2012
 *      Author: devi1013
 */

#ifndef ISYMTABLE_H_
#define ISYMTABLE_H_

#include "SymTable.h"

class ISymTable
{


public:

	/*
	 * Überprüft ob das Lexem vorhanden ist, wenn es nicht vorhanden ist, dann
	 * fügt es in die SymTableEntry ein. Verwaltet wird es durch ein HashTable.
	 * Bei einem INTEGER wird sofort ein Info Objekt erzeugt, ohne über die HashTable
	 * zu gehen. Wenn das Lexem schon existiert, dann wird wird nur vom existirendem
	 * Info Object die Adresse zurückgegeben.
	 *
	 * @param  Um in die HashTable einzufügen und zum überprüfen ob das Lexem vorhanden ist.
	 * @param  Wenn es ein Integer ist, wird der Zahlenwert im Info Container gespeichert.
	 * @return Liefert den Aktuellen Zeiger des Info Objektes zurück.
	 */
	virtual Info* checkLexem( String* lexem , TType* tokenIdent )
	{
		this->checkLexem( lexem , tokenIdent );
	}

};

#endif /* ISYMTABLE_H_ */
