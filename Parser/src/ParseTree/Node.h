/*
 * Node.h
 *
 *  Created on: May 28, 2012
 *      Author: devi1013
 */

#ifndef NODE_H_
#define NODE_H_

#include "IParseTree.h"

#define START_VECTOR_SIZE 1
#define ADD_VECTOR_SIZE 1
#define INIT_LENGTH 0
#define MARKE_BUFFER 5
#define MARK_OVERFLOW 999

class MakeCodeOutput;

class Node
{
private:

	friend class MakeCodeOutput;

	//Anfangpunkt von dem Baum
	Node* root;

	//In welechen Zustand sich die Semantische Analyse sich befindet
	int type;

	//KnotenbeschreibbareVariablen
	NotTerminal notTerminale;
	Info* info;

	//Zeigerarithmetik
	Node** vector;
	int ptrCurrent;
	int ArrayLength;
	int filledArray;

	//Für eindeutige marken
	char* markeUp;
	String* marke1;
	String* marke2;

	//Der Vector wird immer um 2 vergrößert
	void resizeVector();

	void cleanArray();

	//Überprüft die einzelnen Zustände
	void typeCheckROOT();

	void typeCheckPROG();

	void typeCheckARRAY_1();
	void typeCheckARRAY_E();

	void typeCheckDECL();

	void typeCheckDECLS_1();
	void typeCheckDECLS_E();

	void typeCheckSTATEMENT_1();
	void typeCheckSTATEMENT_2();
	void typeCheckSTATEMENT_3();
	void typeCheckSTATEMENT_4();
	void typeCheckSTATEMENT_5();
	void typeCheckSTATEMENT_6();

	void typeCheckSTATEMENTS_1();
	void typeCheckSTATEMENTS_E();

	void typeCheckEXP();

	void typeCheckEXP_2_1();
	void typeCheckEXP_2_2();
	void typeCheckEXP_2_3();
	void typeCheckEXP_2_4();
	void typeCheckEXP_2_5();

	void typeCheckINDEX_1();
	void typeCheckINDEX_E();

	void typeCheckOP_EXP_1();
	void typeCheckOP_EXP_E();

	void typeCheckOP_PLUS();
	void typeCheckOP_MINUS();
	void typeCheckOP_MULT();
	void typeCheckOP_DIV();
	void typeCheckOP_LESS();
	void typeCheckOP_GREATER();
	void typeCheckOP_EQUAL();
	void typeCheckOP_UNEQUAL();
	void typeCheckOP_AND();

	//Bricht die Kontrollierung des Baums ab und schmeißt eine Exception
	void error();

	//Für eindeutige marken
	void createMarke();

	//erzeugt den Assempler code
	void makeCodeROOT();

	void makeCodePROG();

	void makeCodeDECLS_1();
	void makeCodeDECLS_E();

	void makeCodeDECL();

	void makeCodeARRAY_1();
	void makeCodeARRAY_E();

	void makeCodeSTATEMENTS_1();
	void makeCodeSTATEMENTS_E();

	void makeCodeSTATEMENT_1();
	void makeCodeSTATEMENT_2();
	void makeCodeSTATEMENT_3();
	void makeCodeSTATEMENT_4();
	void makeCodeSTATEMENT_5();
	void makeCodeSTATEMENT_6();

	void makeCodeEXP();

	void makeCodeEXP_2_1();
	void makeCodeEXP_2_2();
	void makeCodeEXP_2_3();
	void makeCodeEXP_2_4();
	void makeCodeEXP_2_5();

	void makeCodeINDEX_1();
	void makeCodeINDEX_E();

	void makeCodeOP_EXP_1();
	void makeCodeOP_EXP_E();

	void makeCodeOP_PLUS();
	void makeCodeOP_MINUS();
	void makeCodeOP_MULT();
	void makeCodeOP_DIV();
	void makeCodeOP_LESS();
	void makeCodeOP_GREATER();
	void makeCodeOP_EQUAL();
	void makeCodeOP_UNEQUAL();
	void makeCodeOP_AND();

public:


	//Wird einmal erzeigt für den root Knoten und dann eingefügt
	Node( NotTerminal nt , Info* info );

	//Konstruktor für den root knoten
	Node( MakeCodeOutput* );

	virtual ~Node();

	//Einfügen eines Knoten
	Node* add( NotTerminal nt , Info* info );

	//Gibt die Knoten von links nach rechts zurück
	Node* next();

	//Überprüft den Baum
	void typeCheck();

	//Erzeugt des ausführbaren Code
	void makeCode();

	//    Löschhilfe für den Destruktor
	void treeDelete();

};

#endif /* NODE_H_ */
