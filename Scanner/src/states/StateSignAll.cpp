/*
 * StateSignAll.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */
#include <stdlib.h>
#include "StateSignAll.h"

StateSignAll* StateSignAll::instance = NULL;
StateSignAll::StateSignAll()
{
	isStartState = false;
	isEndState = true;
	type = NOPE ;
}

StateSignAll::~StateSignAll(){}

State* StateSignAll::stateNow()
{
	if (StateSignAll::instance == NULL)
		StateSignAll::instance = new  StateSignAll();
			return StateSignAll::instance ;
}

TType StateSignAll::getType(char * letter)
{
	if (*letter == '+')
		{
			setType(SIGNPLUS);
			return this->type = SIGNPLUS;
		}
	else if (*letter == '-')
		{
		setType(SIGNMINUS);
			return type = SIGNMINUS;

		}
	else if (*letter == '*')
		{
		setType(SIGNSTAR);
			return type = SIGNSTAR;

		}
	else if (*letter == '>')
		{
		setType(SIGNHIGHER_THAN);
			return type = SIGNHIGHER_THAN;

		}
	else if (*letter == '=')
			{
		setType(SIGNEQUAL);
			return type = SIGNEQUAL;

			}
	else if (*letter == '!')
			{
		setType(SIGNATTENTION);
			return type = SIGNATTENTION;

			}
	else if (*letter == '&')
			{
		setType(SIGNAND);
				return type = SIGNAND;
			}
	else if (*letter == ';')
			{
		setType(SIGNSEMICOLON);
				return type = SIGNSEMICOLON;
			}
	else if (*letter == '(')
			{
		setType(SIGNROUNDBRACKET_OPEN);
				return type = SIGNROUNDBRACKET_OPEN;
			}
	else if (*letter == ')')
			{
		setType(SIGNROUNDBRACKET_CLOSE);
			return type = SIGNROUNDBRACKET_CLOSE;
			}
	else if (*letter == '{')
			{
		setType(SIGNCURLYBRACKET_OPEN);
				return type = SIGNCURLYBRACKET_OPEN;
			}
	else if (*letter == '}')
			{
		setType(SIGNSQUAREBRACKET_OPEN);
			return type = SIGNCURLYBRACKET_CLOSE;
			}
	else if (*letter == '[')
			{
		setType(SIGNSQUAREBRACKET_OPEN);
				return type = SIGNSQUAREBRACKET_OPEN;
			}
	else if (*letter == ']')
			{
		setType(SIGNSQUAREBRACKET_CLOSE);
				return type = SIGNSQUAREBRACKET_CLOSE;
			}
	}

State* StateSignAll::work(char * letter)
{
	return StateStart::stateNow();
}

void StateSignAll::setType(TType type)
{
this->type = type;
}







