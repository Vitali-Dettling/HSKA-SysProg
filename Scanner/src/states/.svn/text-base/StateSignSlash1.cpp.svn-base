/*
 * StateSignSlash1.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */
#include <stdlib.h>
#include "StateSignSlash1.h"
#include "StateSignStar1.h"

StateSignSlash1* StateSignSlash1::instance = NULL;

StateSignSlash1::StateSignSlash1()
{
	isStartState = false;
	isEndState = true;
	type = SIGNSLASH;
}
StateSignSlash1::~StateSignSlash1(){}

State* StateSignSlash1::stateNow()
{
	if (StateSignSlash1::instance == NULL)
		StateSignSlash1::instance = new  StateSignSlash1();
				return StateSignSlash1::instance ;
}

State* StateSignSlash1::work(char * letter)
{
	if (*letter == '*')
	{
		return StateSignStar1::stateNow();
	}
	else
		return StateStart::stateNow();

}
