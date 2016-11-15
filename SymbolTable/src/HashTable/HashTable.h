/*
 * HashTable.h
 *
 *  Created on: Apr 1, 2012
 *      Author: devi1013
 */

#ifndef __HASHTABLE__INCLUDED__
#define __HASHTABLE__INCLUDED__

#include "../Container/Info.h"
#include <stdio.h>
#include "SymTableEntry.h"
#include "HashList.h"

template < class valueType >
class HashTable
{
private:

  //Länge des Arraies
  unsigned int size;

  //Einstiegspunkt
  HashList< SymTableEntry < valueType > >* root;

public:


  HashTable( unsigned int _size )
  {


	  try//Überprüft die allocation des HashListe
	  {
		  //Wenn die Größe zu klein ist
		  if(_size < 10 ){throw _size;}
		  else
		  {
				size = _size;
				root = new HashList< SymTableEntry < valueType > >[_size];
		  }
	  }
	  catch(const int * ex)//size < 10 -> Exception.
	  {
		 printf("Exception: Die Größe ist kleiner als 10: -> %d\n", ex);
		 printf("--> Exception: Die HashList wurde nicht allokiert.\n");
	  }
  }

  ~HashTable()
  {
	delete[] root;
	root = 0; //Sichert den Zeiger
  }

  // Calculate the hash code and transform the code to the index of the Array.
  unsigned int getIndex( String* key) const
  {


	  unsigned long hashNr = 0;
	  unsigned int n = key->length();

	  //Summurate the ASCII code of the string together and modulate it throw the size of the array.
	  hashNr = ( (16 * 'key[ 0 ]') + (8 * 'key[ n-1 ]') )  + n ;

	  return hashNr % this->size;

  }

  //Fügt am letzen Element an
  Info* insert(String* key, valueType value)const
  {

	 HashList< SymTableEntry < valueType > >* Element = root;
	int _index = getIndex(key);

	//Erstellt und fügt es an
	Element[_index].insertLastElement(new SymTableEntry< valueType >( key , value ) );

	//Gibt den Zeiger auf auf die Info zurück
	return Element[_index].getLast()->info;//If the key was not before in the hash table.
  }

  //Gibt den Zeiger auf den aktuellen Kontainer zurück ansonsten NULL
  Info* contains( String* key )const
  {
		int _index = getIndex(key);

  		HashList<SymTableEntry< valueType > >* Element = root;
		Element[_index].resetCurrent();//Setzt den aktuellen Zeiger auf die erste Stelle

		//Wenn das Lexem existiert
		while(Element[_index].hasNext() == true)
		{
			//Überprüft ob das Lexe, schon vorhanden ist
			if( Element[_index].getCurrent()->key->compare( key ) )
			{
				return Element[_index].getCurrent()->info;
			}
			//Geht mit dem Current Zeiger zum nächsten Element
			Element[_index].next();
		}

		//Das Lexem ist nicht in der Liste
		return NULL;

  }
};


#endif // __HashTable__INCLUDED__
