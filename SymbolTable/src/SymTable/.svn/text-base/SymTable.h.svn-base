/*
 * SymTable.h
 *
 *  Created on: Apr 11, 2012
 *      Author: devi1013
 */

#ifndef SYMTABLE_H_
#define SYMTABLE_H_

#include "../../../String/src/IString.h"
#include "../../../Scanner/src/TType.h"
#include "../Container/Info.h"
#include "../HashTable/HashTable.h"
#include "stdlib.h"

class SymTable
{

private:

	HashTable< TType >* hashTable;

public:
	SymTable( unsigned int hashSize );
	virtual ~SymTable();


	//Überprüft das Lexem und IDENTIFIRE und fügt es ein, fals noch nicht vorhanden
	Info* checkLexem( String* lexem , TType tokenType);



};

#endif /* SYMTABLE_H_ */
