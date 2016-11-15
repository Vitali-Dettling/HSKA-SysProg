/*
 * SymTable.cpp
 *
 *  Created on: Apr 11, 2012
 *      Author: devi1013
 */

#include "SymTable.h"


SymTable::SymTable( unsigned int hashSize )
{
	hashTable = new HashTable< TType >( hashSize );
}

//Überprüft das Lexem und IDENTIFIRE und fügt es ein, fals noch nicht vorhanden
Info* SymTable::checkLexem( String* lexem  , TType tokenType )
{
	Info* _info = NULL;

	//Nur wenn es TType = INTERGER ist
	if( tokenType == INTEGER )
	{
		_info = new Info( tokenType ,  lexem->getValue() , lexem );
	}
	else
	{
		_info = hashTable->contains( lexem );

		//Wenn es nicht vorhanden war, dann wird es eingefügt
		if( _info == NULL )
		{
			//Fügt das Lexem ein
			_info = hashTable->insert( lexem , tokenType );
		}
	}

	//Überprüft ob ein Eintrag tatsächlich gemacht wurden ist
	try
	{
		if(_info == NULL)
		{
			throw "Der String wurde nicht eingefügt und somit wurde keine Info Klasse erstellt. \n";
		}
	}
	catch( const char* ex )
	{
		printf(ex);
	}

	return _info;
}

SymTable::~SymTable()
{
	delete hashTable;
}
