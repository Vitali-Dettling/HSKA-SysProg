/*
 * StateInteger.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#include <stdlib.h>
#include "StateInteger.h"

StateInteger* StateInteger::instance = NULL;

StateInteger::StateInteger()
{
isStartState = false;
isEndState = true;
type = INTEGER;
}

StateInteger::~StateInteger(){}

State* StateInteger::stateNow()
{
	if (StateInteger::instance == NULL)
		StateInteger::instance = new  StateInteger();
			return StateInteger::instance ;
}

State* StateInteger::work(char * letter)
{
	if((*letter >= '0') && (*letter <= '9'))
	{
	return StateInteger::stateNow();
	}
	else
	{
		return StateStart::stateNow();
	}
}
