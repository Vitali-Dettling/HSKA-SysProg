/*
 * testMain.cpp
 *
 *  Created on: Apr 29, 2012
 *      Author: devi1013
 */

#include "ISymTable.h"
#include "../../../Scanner/src/TType.h"
#include <iostream>

using namespace std;

int main()
{


	String* s = new String();
	String* z = new String();
	String* c = new String();
	SymTable* st = new SymTable(10);
	Info* i;
	Info* i2;



	char* e = new char[1];

	*e = 'x';
	cout << e << endl;
	z->add( e );


	*e = 'x';
	cout << e << endl;
	s->add( e );

	printf("\n");
	cout << "Erkennt die SimTable einen Lexem, dass schon vorhanden ist?" << endl;
	i = st->checkLexem( z , READ );
	cout << "Info Container Adresse: " << i << endl;
	cout << "TTYpe: " << i->getTTypeInfo() << endl;
	cout << "Value: :" << i->getValueInfo() << endl;

	printf("\n");
	cout << "Erneute Eingabe des gleichen Lexems" << endl;
	i2 = st->checkLexem( s , READ );
	cout << "Info Container Adresse : " << i2 << endl;
	cout << "TTYpe: " << i2->getTTypeInfo() << endl;
	cout << "Value: :" << i2->getValueInfo() << endl;







/*	Zwei geleiche read werden eingefügt.
 * Einmal durch den Konstreuktor und
 * einmal durch add Methode


	char* r = "read";
	String* sr = new String( r );


	char* e = new char[4];

	*e = 'r';
	cout << e << endl;
	s->add( e );
	*e = 'e';
	cout << e << endl;
	s->add( e );
	*e = 'a';
	cout << e << endl;
	s->add( e );
	*e = 'd';
	cout << e << endl;
	s->add( e );


	cout << "String input: " << sr->getString() << endl;


	printf("\n");
	cout << "Erkennt die SimTable einen Lexem, dass schon vorhanden ist?" << endl;
	i = st->checkLexem( sr , READ );
	cout << "Info Container Adresse: " << i << endl;
	cout << "TTYpe: " << i->getTTypeInfo() << endl;
	cout << "Value: :" << i->getValueInfo() << endl;

	printf("\n");
	cout << "Erneute Eingabe des gleichen Lexems" << endl;
	i2 = st->checkLexem( s , IDENTIFIER );
	cout << "Info Container Adresse : " << i2 << endl;
	cout << "TTYpe: " << i2->getTTypeInfo() << endl;
	cout << "Value: :" << i2->getValueInfo() << endl;

*/

	/*
	char* x = new char[5];

	for(int i = 0 ; i < 5 ; i++)
	{
		x[ i ] = 'a';
		cout << x[ i ];
		s->add( x );
	}


	printf("\n");
	cout << "Fügt in die HashTable ein." << endl;
	i = st->checkLexem( s ,SIGNAND );
	cout << "Info Speicheradresse: " << i << endl;

	printf("\n");
	cout << "Ließt die Werte aus dem Info Kontainer aus." << endl;
	cout << "Ließt den TType wieder aus -> " << i->getTTypeInfo() << endl;
	cout << "Ließt den Wert aus, der aber NULL sein sollt -> " << i->getValueInfo() << endl;

	printf("\n");
	cout << "Es ist kein INTEGER TType -> somit sollte nicht verändert werden." << endl;
	cout << "Die Speicheradresse stimmt überein -> " << st->checkLexem( s , SIGNAND ) << endl;

	printf("\n");
	cout << "Es ist kein INTEGER TType -> somit sollte nicht verändert werden." << endl;
	cout << "Die Speicheradresse stimmt überein -> " << st->checkLexem( s , SIGNAND ) << endl;


	for(int i = 0 ; i < 5 ; i++)
	{
		x[ i ] = '1';
		cout << x[ i ];
		z->add( x );
	}
	z->calcValue();

	printf("\n");
	cout << "Ein char mit zahlen wird abgespeichert." << endl;
	cout << "Fügt in die HashTable ein." << endl;
	i = st->checkLexem( z ,INTEGER );
	cout << "Info Speicheradresse: " << i << endl;

	printf("\n");
	cout << "Ließt die Werte aus dem Info Kontainer aus." << endl;
	cout << "Ließt den TType wieder aus -> " << i->getTTypeInfo() << endl;
	cout << "Ließt den Wert aus, 11111 sollte es sein -> " << i->getValueInfo() << endl;

	printf("\n");
	cout << "Es ist ein INTEGER TType -> somit sollte nicht verändert werden." << endl;
	cout << "Die Speicheradresse stimmt überein -> " << st->checkLexem( z , INTEGER ) << endl;
	cout << "Ließt den TType wieder aus -> " << i->getTTypeInfo() << endl;
	cout << "Ließt den Wert aus, der aber 11111 sein sollt -> " << i->getValueInfo() << endl;

	for(int i = 0 ; i < 3 ; i++)
	{
		x[ i ] = 'f';
		cout << x[ i ];
		c->add( x );
	}

	printf("\n");
	printf("\n");
	cout << "Fügt in die HashTable ein." << endl;
	i = st->checkLexem( c ,IDENTIFIER );
	cout << "Info Speicheradresse: " << i << endl;

	printf("\n");
	cout << "Ließt die Werte aus dem Info Kontainer aus." << endl;
	cout << "Der HsshCode sollte unterschiedlich sein" << endl;

	for(int i = 0 ; i < 3 ; i++)
	{
		x[ i ] = 'f';
		cout << x[ i ];
		c->add( x );
	}

	printf("\n");
	cout << "Fügt in die HashTable ein." << endl;
	i = st->checkLexem( c ,IDENTIFIER );
	cout << "Info Speicheradresse: " << i << endl;

	printf("\n");
	cout << "Ließt die Werte aus dem Info Kontainer aus." << endl;
	cout << "Der HsshCode sollte unterschiedlich sein" << endl;

	for(int i = 0 ; i < 3 ; i++)
	{
		x[ i ] = 'f';
		cout << x[ i ];
		c->add( x );
	}

	printf("\n");
	cout << "Fügt in die HashTable ein." << endl;
	i = st->checkLexem( c ,IDENTIFIER );
	cout << "Info Speicheradresse: " << i << endl;

	printf("\n");
	cout << "Ließt die Werte aus dem Info Kontainer aus." << endl;
	cout << "Der HsshCode sollte unterschiedlich sein" << endl;
*/

	return 0;
}


