/*
 * StateERROR.cpp
 *
 *  Created on: May 7, 2012
 *      Author: voma1018
 */

#include "StateERROR.h"
#include "stdlib.h"

StateERROR* StateERROR::instance = NULL;

StateERROR::StateERROR()
{
	isStartState = false;
	isEndState = true;
	type = ERROR;
}

StateERROR::~StateERROR() {}

State* StateERROR::stateNow()
{
	if (StateERROR::instance == NULL)
		StateERROR::instance = new  StateERROR();
			return StateERROR::instance ;
}

State* StateERROR::work(char * letter)
{
	return StateStart::stateNow();
}

TType StateERROR::getType()
{
	return type;
}
