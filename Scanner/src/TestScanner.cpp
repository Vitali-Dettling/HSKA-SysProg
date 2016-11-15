/*
 * TestScanner.cpp
 *
 *  Created on: May 1, 2012
 *      Author: voma1018
 */

#include <stdio.h>
#include <iostream>
#include "Scanner.h"
#include "ScannerImp.h"
#include "Automat.h"
#include "TType.h"
#include "../../Buffer/src/IBuffer.h"

using namespace std;

int main(int argv, char* argc[])
{

	// !!!!!!!!   TEST    SCANNER    !!!!!!!!

	ScannerImp* scannerTest = new ScannerImp(argc[1]);
	Token* t;
	WriteBuffer write;
	int i =0;

	while(t!= NULL)
		{
			if(i==11){
				cout<< "hier!!"<< endl;
			}
			cout<< i<< endl;
			t = scannerTest->nextToken();
			write.writeFiel(t);
			scannerTest->freeToken(t);
			i++;
		}

cout << "fertig!!" << endl;

return 0;
}
