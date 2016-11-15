/*
 * testMain.cpp
 *
 *  Created on: Apr 9, 2012
 *      Author: devi1013
 */



#include "IBuffer.h"
#include <pthread.h>
#include "../../Scanner/src/Token.h"
#include "../../Scanner/src/TType.h"
#include "../../SymbolTable/src/SymTable/ISymTable.h"


#include <iostream>
using namespace std;


int main( int arcv , char * argc[] )
{
	ReadBuffer b( argc[1] );

	long arg;
	arg = 0;

	    cout << "--- Test: Zweiter Buffer wird befüllt" << endl;
		printf("\n");
		cout << "File hat mehrere Zeichen: " << endl;
		cout << "FilePos geht ein Zeicher vor und zurück: " << endl;
		b.nextChar();
		b.ungetChar( 1 );
		cout << "FilePos sollte wieder 0 haben: " << endl;

		printf("\n");
		cout << "Zweiter Buffer wird befüllt: " << endl;
		cout << "secondBuffer wird angezeigt: " << endl;
		for(int i = 0 ; i < READ_BUFFER_SIZE ; i++){  b.nextChar() ; }
		cout << b.nextChar() ;

		printf("\n");
		cout << "FilePos geht ein Zeichen vor: " << endl;
		cout << "FilePos wird nicht geändert -> EOF: " << endl;
		cout << b.nextChar() << endl;
		cout << "FilePos geht bis zum ersten Buffer zurück -> 4 müsste angezeigt werden: " << endl;
		b.ungetChar( 3 );
		cout << b.nextChar();



		cout << "--- Test: Wiederfüllen des ersten Buffers" << endl;
		printf("\n");
		cout << "Dritter Buffer wird gefüllt: " << endl;
		cout << "firstBuffer wird ein zweites mal auftauchen: " << endl;
		for(int i = 0 ; i < READ_BUFFER_SIZE*2 ; i++){ cout << b.nextChar() << endl ; }
		cout << "a solte zum Schluss angezeigt werden: " << endl;
		cout << b.nextChar() << endl;



		cout << "--- Test: Der dritte Buffer wird befüllt." << endl;
		printf("\n");
		cout << "Vierten Buffer wird gefüllt: " << endl;
		cout << "secondBuffer wird ein zweites mal auftauchen: " << endl;
		for(int i = 0 ; i < READ_BUFFER_SIZE*3 ; i++){ cout << b.nextChar() << endl ; }
		cout << "'seciondBuffer' und 'e' solte zum Schluss angezeigt werden: " << endl;
		cout << b.nextChar() << endl;



		printf("\n");
		cout << "Geht 2 schritt zurück: " << endl;
		cout << "filePos solte 4 ergeben: " << endl;
		b.ungetChar( 2 );


		printf("\n");
		cout << "Geht 5 schritt zurück: " << endl;
		cout << "'b' sollte angezeigt werden: " << endl;
		b.ungetChar( 5 );
		cout << b.nextChar() << endl;


/*
	//ReadBuffer b( argc[1] );
	WriteBuffer bw;

	Info* i = new Info( IDENTIFIER, NULL );

	//char* x = "read";

	//Erste Werte Ausgabe
	char* y = new char[3];

	y[0] = 'H';
	y[1] = 'a';
	y[2] = 'b';

	String* s = new String();

	char* in = y;

	s->add( in );
	in++;
	s->add( in );
	in++;
	s->add( in );

	Token* t = new Token( 0 , 0 , s , i);


	//Zweiter Werte Ausgabe
	char* y2 = new char[3];

	y2[0] = '2';
	y2[1] = '2';
	y2[2] = '2';

	String* s2 = new String();

	char* in2 = y2;

	s2->add( in2 );
	in2++;
	s2->add( in2 );
	in2++;
	s2->add( in2 );

	s2->calcValue();

	Info* i2 = new Info( INTEGER, s2->getValue() );

	Token* t2 = new Token( 0 , 0 , s2 , i2);





	bw.writeFiel( t );

	bw.writeFiel( t2 );

	t = NULL;

	bw.writeFiel( t );



*/

/*

	ReadBuffer b( argc[1] );


	cout << "Output: " << b.nextChar() << endl;
	cout << "Output: " << b.nextChar() << endl;
	cout << "Output: " << b.nextChar() << endl;
	cout << "Output: " << b.nextChar() << endl;
	cout << "Output: " << b.nextChar() << endl;
	cout << "Output: " << b.nextChar() << endl;

*/
/*
	cout << "--- Test: Leeres File ---" << endl;
	printf("\n");
	//Verwenden, wenn ein leeres File eingelessen wird
    cout << "File ist leer: " << endl;
	cout << "Geht 1 zurück -> Exception :" << endl;
	b.ungetChar( 1 );

	printf("\n");
	//Verwenden, wenn ein leeres File eingelessen wird
	cout << "File ist leer: " << endl;
	cout << "Will das nächste Zeichen -> Bekommt EOF zurück:" << endl;
	b.nextChar();
*/
/*
   cout << "--- Test: Exception tests ---" << endl;
    printf("\n");
	cout << "FilePos ist am ersten Zeichen: " << endl;
	cout << "Geht 1 zurück -> Exception: " << endl;
	b.ungetChar( 1 );

	printf("\n");
	cout << "unget = 0 ist ungültig: " << endl;
	cout << "Geht 0 zurück -> Exception: " << endl;
	b.ungetChar( 0 );

	printf("\n");
	cout << "unget < 0 ist ungültig: " << endl;
	cout << "Geht -1 zurück -> Exception: " << endl;
	b.ungetChar( -1 );

	printf("\n");
	cout << "unget überscreitet der beiden Buffergrößen: " << endl;
	cout << "Geht unget = beider BufferGrößen -> Exception: " << endl;
	b.ungetChar( 2*BUFFER_SIZE );
*/

	return 0;
}
