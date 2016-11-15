/*
 * ParserImp.h
 *
 *  Created on: May 29, 2012
 *      Author: voma1018
 */

#ifndef PARSERIMP_H_
#define PARSERIMP_H_

#include "../../../Scanner/src/IScanner.h"  // hier bekomme ich die Tokens her
#include "../../../Scanner/src/TType.h" // TTypes
#include "../../../Scanner/src/Token.h"
#include "../NotTerminal.h" // PROG DESC usw.
#include "../ParseTree/Node.h"  //Knoten
#include "../ParseTree/IParseTree.h"	// ParserTREE

class ParserImp {

	Token* toke;
	ScannerImp* myScan;
	Node* node;
	MakeCodeOutput* makeCode;
	bool error;
	void errorM();
	void getNextToken();

public:
	ParserImp(char* data);
	virtual ~ParserImp();

	void parse();
	void prog(Node*);
	void decls(Node*);
	void decl(Node*);
	void array(Node*);
	void statements(Node*);
	void statement(Node*);
	void exp(Node*);
	void exp2(Node*);
	void index(Node*);
	void op_exp(Node*);
	void op(Node*);


};

#endif /* PARSERIMP_H_ */
