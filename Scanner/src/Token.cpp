/*
 * Token.cpp
 *
 *  Created on: 09.04.2012
 *      Author: voma1018
 */

#include "Token.h"

Token::Token(){}

Token::Token(int column, int row, String* str, Info* key)
{
	this->column = column;
	this->row = row;
	this->str = str;
	this->key = key;
	this->type = key->getTTypeInfo();

}

Token::Token(int column, int row, String* str, TType type)
{
	this->column = column;
	this->row = row;
	this->str = str;
	this->type = type;

}

Token::~Token(){}


int Token::getColumn(){
	return this->column;
}
	int Token::getRow(){
		return this->row;
	}
	String* Token::getLexem(){
		return this->str;
	}

	Info* Token::getKey(){
		return this->key;
	}

	TType Token::getTType(){
		return this->type;

	}
