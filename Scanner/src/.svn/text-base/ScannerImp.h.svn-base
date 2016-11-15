/*
 * ScannerImp.h
 *
 *  Created on: 17.04.2012
 *      Author: voma1018
 */

#ifndef SCANNERIMP_H_
#define SCANNERIMP_H_

#include "../../SymbolTable/src/SymTable/ISymTable.h"
#include "Automat.h"
#include "../../Buffer/src/IBuffer.h"
#include "../../String/src/IString.h"
#include "Scanner.h"
#include "Token.h"
#include "TType.h"


class ScannerImp:public Scanner
{
	int actualLine, actualColomn, size, firstLine, firstColumn;
	bool comment, mark;
	TType currentType, lastType;
	ReadBuffer* myBuffer;
	SymTable* mySymTable;
	Automat* myAutomat;
	int* commentMark;



	/*
	 * Initialisierung von einigen Variabeln
	 *
	 * */
	void init();

public:
	// Standardkonstruktor
	ScannerImp();

	/*
	 * Konstruktor
	 *
	 * @param char*
	 * 			Die Datei, die eingelesen werden soll
	 * **/
	ScannerImp(char*);

	// Destruktor
	virtual ~ScannerImp();

	// Setter (Comment)
	void setComment(bool);

	/*
	 * Erstellt ein Token mit den Eigenschaften die dazugehören.
	 *
	 * @return Token
	 *
	 * **/
	virtual Token* mkToken(TType type);

	/*
	 * Zurückgehen in dem Buffer
	 *
	 * @param int
	 * 			Anzahl die zurück gehen soll
	 * **/
	virtual void ungetChar(int count);

	/*
	 * Beendet einige Prozesse
	 *
	 * **/
	virtual void stop();

	/**
	 * Methode welches ein Token herausfindet
	 *
	 * @return Token
	 *
	 * */
	virtual Token* nextToken();

	/*
	 * Löscht das Token
	 *
	 * @param Token
	 * 			Token welches gelöscht werden soll
	 * **/
	virtual void freeToken(Token*);

};

#endif /* SCANNERIMP_H_ */
