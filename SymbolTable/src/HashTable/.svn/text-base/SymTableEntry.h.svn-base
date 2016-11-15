/*
 * SymTableEntry.h
 *
 *  Created on: Apr 1, 2012
 *      Author: devi1013
 */

#ifndef __PAIR__INCLUDED__
#define __PAIR__INCLUDED__

#include "../../../String/src/IString.h"
#include "../Container/Info.h"

template < class type >
class HashList;

template < class valueType >
class SymTableEntry
{

public:

	friend class HashList< SymTableEntry >;

	//Zeigt auf den nächsten Knoten
	SymTableEntry< valueType >* next;

	//Key ist in diesem Fall das Lexem
	String*      key;

	//Speichert in den Container
	Info* info;


  SymTableEntry(String* _key, valueType _value , SymTableEntry< valueType>* _next = 0 )
  {
	this->key = _key;
	this->next = _next;

	//Lexem wird abgespeichert
	store( _value , _key );
  }

//Erzeigt einen neuen Eintrag in im Kontainer -> valueType ist in diesem Fall TType
  void store( valueType tokenType , String* lexem )
  {
	  this->info = new Info( tokenType , NULL , lexem );
  }

  ~SymTableEntry()
  {
	  delete this->info;
  }

};

#endif // __SymTableEntry__INCLUDED__
