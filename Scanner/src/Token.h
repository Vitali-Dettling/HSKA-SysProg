/*
 * Token.h
 *
 *  Created on: 09.04.2012
 *      Author: voma1018
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include "TType.h"
#include "../../SymbolTable/src/Container/Info.h"
#include "../../String/src/IString.h"

class Token {
	int column, row;
	Info* key;
	String* str;
	TType type;

public:
	// Standardkonstruktor
	Token();
	/*
	 * Konstruktor für Identifier und Integer
	 *
	 * @param	int
	 * 			Spalte
	 * @param	int
	 * 			Zeile
	 * @param	String*
	 * 			Name
	 * @param	Info*
	 * 			Key
	 * */
	Token(int column, int row, String* str, Info* key);
	/*
	 * Konstruktor für den Rest
	 *
	 * @param	int
	 * 			Spalte
	 * @param	int
	 * 			Zeile
	 * @param	String*
	 * 			Name
	 * @param	TType
	 * 			Token Typ
	 * */
	Token(int column, int row, String* str, TType type);
	virtual ~Token();

	int getColumn();
	int getRow();
	String* getLexem();
	Info* getKey();
	TType getTType();

};

#endif /* TOKEN_H_ */
