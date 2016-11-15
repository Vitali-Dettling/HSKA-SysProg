/*
 * StateIdentifier.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */
#include <stdlib.h>

#include "StateIdentifier.h"

StateIdentifier* StateIdentifier::instance = NULL;

StateIdentifier::StateIdentifier()
{
	isStartState = false;
	isEndState = true;
	type = IDENTIFIER;
}

StateIdentifier::~StateIdentifier(){}
State* StateIdentifier::stateNow()
{
	if (StateIdentifier::instance == NULL)
		StateIdentifier::instance = new  StateIdentifier();
				return StateIdentifier::instance ;
}


State* StateIdentifier::work(char * letter)
{
	if (((*letter >= 'A') && (*letter <= 'Z')) || ((*letter >= 'a') && (*letter <= 'z')) || ((*letter>= '0') && (*letter <= '9')))
		{
		return StateIdentifier::stateNow();
		}

	else
	{
		return StateStart::stateNow();
	}

}

TType StateIdentifier::getType()
{
	return type;
}

