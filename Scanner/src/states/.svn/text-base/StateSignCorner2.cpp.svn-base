/*
 * StateSignCorner2.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#include <stdlib.h>
#include "StateSignCorner2.h"

StateSignCorner2* StateSignCorner2::instance = NULL;

StateSignCorner2::StateSignCorner2()
{
	isStartState = false;
	isEndState = true;
	type = SIGNCOMPLEX;
}
StateSignCorner2::~StateSignCorner2(){}

State* StateSignCorner2::stateNow()
{
	if (StateSignCorner2::instance == NULL)
		StateSignCorner2::instance = new  StateSignCorner2();
	return StateSignCorner2::instance ;
}
State* StateSignCorner2::work(char * letter)
{
	return StateStart::stateNow();
}
