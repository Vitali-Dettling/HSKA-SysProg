/*
 * StateStart.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#define BLANK ' '
#define ENTER '\n'

#include "StateStart.h"
#include <stdlib.h>
#include "StateIdentifier.h"
#include "StateInteger.h"
#include "StateSignAll.h"
#include "StateSignCorner1.h"
#include "StateSignSlash1.h"
#include "StateERROR.h"
#include "../Automat.h"

StateStart* StateStart::instance = NULL;

bool isStartState;
bool isEndState ;



StateStart::StateStart()
{
	isStartState = true;
	isEndState = false;
	type = NOPE;
}

StateStart::~StateStart(){}

State* StateStart::work(char* letter)
{
	if (((*letter >= 'A') && (*letter <= 'Z')) || ((*letter >= 'a') && (*letter <= 'z')))
	{
		return StateIdentifier::stateNow();
	}

	else if((*letter>= '0') && (*letter <= '9'))
	{
		return StateInteger::stateNow();
	}

	else if(*letter =='/')
	{
		return StateSignSlash1::stateNow();
	}

	else if(*letter == '<')
	{
		return StateSignCorner1::stateNow();

	}

	else if(  (*letter == '!') | (*letter == '&') | ( *letter == '(') | (*letter == '+') | (*letter == '-') | (*letter == ';')
			| (*letter == '=') | (*letter == '>') | ( *letter == '[') | (*letter == ']') | (*letter == '{') | (*letter == '}')
			| (*letter == '*') | (*letter == ')'))
	{
		StateSignAll* result = (StateSignAll*)StateSignAll::stateNow();
		result->getType(letter);

		return StateSignAll::stateNow();

	}

	else
	{
		return StateERROR::stateNow();
	}
}



State* StateStart::stateNow()
{
	if (StateStart::instance == NULL)
		StateStart::instance = new  StateStart();
					return StateStart::instance ;
}
TType StateStart::getType()
{
	return type;
}
