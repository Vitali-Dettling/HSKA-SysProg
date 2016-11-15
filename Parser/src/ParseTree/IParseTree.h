/*
 * IParseTree.h
 *
 *  Created on: May 28, 2012
 *      Author: devi1013
 */

#ifndef IPARSETREE_H_
#define IPARSETREE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "stdlib.h"
#include <errno.h>
#include <string.h>
#include "../NotTerminal.h"
#include "../TypeInfo.h"
#include "../../../SymbolTable/src/SymTable/ISymTable.h"
#include "../../../String/src/IString.h"
#include "MakeCodeOutput.h"


class MakeCodeOutput;

class IParseTree
{

public:

	/*
	 * Überfrüft den Baum ob es Semantische Fehler beinhaltet.
	 * Beim Fehlerfall wird eine Exception geworfen und die Überprüfung wird unterbrochen.
	 *
	 * @param	rootNode
	 * 			Anfangskroten des Baumes der untersucht werden muss
	 */
	virtual void typeCheck() = 0;

	/*
	 * Wenn die Semantik und die Syntaktik stimmt wir der code
	 * in eine Test Datei geschrieben.
	 */
	virtual void makeCode() = 0;

};

#endif /* IPARSETREE_H_ */
