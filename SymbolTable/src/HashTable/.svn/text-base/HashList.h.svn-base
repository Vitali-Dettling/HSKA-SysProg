/*
 * HashList.h
 *
 *  Created on: Apr 1, 2012
 *      Author: devi1013
 */

#ifndef __HASHLIST__INCLUDED__
#define __HASHLIST__INCLUDED__

#include <stdio.h>

template <class type>
class HashList
{
private:

	//Zeiger auf Knoten
	type* first;
	type* last;
	type* current;

	unsigned int size;

public:

	HashList():first(NULL),last(NULL),current(NULL)
	{
		this->size = 0;
	}

	//Delte the hole list.
	~HashList()
	{
		type* _next = first->next;
		delete first;
		first = _next;
	}

	type* getFirst() const { return first; }//Erstes Element
	type* getLast() const { return last; }//Letztes Element.
	type* getCurrent() const { return current; }//Aktuelles Element.
	unsigned int getSize() const { return size; }//Größe des Tabelle
	void resetCurrent() { current = first;}//Setzt den Aktuellen Zeiger zurück
	void next(){ current = current->next; }//Nächstes Element

	//Wenn es ein nächstes Element gibt
	bool hasNext()const
	{
		//Es gibt kein Element in der liste
		if(first == NULL){ return false; }

		//Nächste Element das in der Liste ist
		if(current != NULL){ return true; }

		return false;
	}

	//Fügt an die letzte Stelle an
	void insertLastElement(type*  _newPair)
	{
		if(first == NULL)
		{
			first = _newPair;
			current = _newPair;
		}
		else//Fügt an die letzte Stelle ein
		{
			last->next = _newPair;
		}
		last = _newPair;
		size++;
	}
};

#endif // __HASHLIST__INCLUDED__
