/*
 * StateSignSlash2.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */
#include <stdlib.h>
#include "StateSignSlash2.h"

StateSignSlash2* StateSignSlash2::instance = NULL;

StateSignSlash2::StateSignSlash2()
{
	isStartState = false;
	isEndState = true;
	type = COMMENT;
}

StateSignSlash2::~StateSignSlash2(){}

State* StateSignSlash2::stateNow()
{
	if (StateSignSlash2::instance == NULL)
		StateSignSlash2::instance = new  StateSignSlash2();
			return (State*) StateSignSlash2::instance ;
}

State* StateSignSlash2::work(char *letter)
{

	return StateStart::stateNow();
}
