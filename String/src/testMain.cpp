/*
 * testMain.cpp
 *
 *  Created on: Apr 1, 2012
 *      Author: devi1013
 */

/*
 * Main.cpp
 *
 *  Created on: Apr 1, 2012
 *      Author: dev1013
 */

#include "String.h"
#include <iostream>


using namespace std;
int main()
{

	int val;
	char* t = new    char(1);
	t[0] = 'a';

	String s;
	String l;
 //   String sv("123");
//	String sc("12test");


	printf("Vergrößern des Arraies\n");

	for( int i = 0 ; i < 21 ; i++ )
	{

		s.add( t );
	}



	for( int i = 0 ; i < 21 ; i++ )
	{
		cout << s[i];
	}



/*
	printf("\n--- Test die add Methode ---\n");
	for(int i = 0 ; i < 20 ; i++){ s.add(&t); }
	cout <<"Gibt eine Zeichenkette von 20 aus:" << s.getString() << endl;
	s.add(&t);
	cout <<"Gibt eine Zeichenkette von 21 aus:" << s.getString() << endl;
	for(int i = 0 ; i < 19 ; i++){ s.add(&t); }
	cout <<"Gibt eine Zeichenkette von 40 aus:" << s.getString() << endl;
	s.add(&t);
	cout <<"Gibt eine Zeichenkette von 41 aus:" << s.getString() << endl;

	/*
	printf("\n--- Test Value methode:---\n");
	val = sv.value();
	printf("Korekte Übergabe mit 123: %d\n" , val);
	val = sc.value();
	printf("--> Exception solte geschmießen, weil charatere in Berechnung: %d\n" , val);
	val = l.value();
	printf("--> Exception solte geschmießen, weil Object leer: %d\n" , val);
/*
	printf("\n--- Test der string Länge ---\n");
	printf("Länge des Strings test: %d\n" , sc.lenght());
	printf("Länge des Strings 123: %d\n" , sv.lenght());
	printf("Länge eines lehren Strings %d\n" , l.lenght());
*/
	/*
	printf("\n--- Test der return Methode ---\n");
	cout <<"Gibt eine Zeichenkette von test aus:" << sc.getString() << endl;
	cout <<"Gibt eine Zeichenkette von 123 aus:" << sv.getString() << endl;


	printf("\n--- Test des überladenen operators== ---\n");
	cout << s == l << endl;

*/



	getchar();

	return 0;
};






