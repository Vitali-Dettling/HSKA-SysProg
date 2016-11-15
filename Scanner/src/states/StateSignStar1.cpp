/*
 * StateSignStar1.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */
#include <stdlib.h>
#include "StateSignStar1.h"
#include "StateSignStar2.h"

StateSignStar1* StateSignStar1::instance = NULL;

StateSignStar1::StateSignStar1()
{
	isStartState = false;
	isEndState = false;
	type = SIGNSLASH;
}
StateSignStar1::~StateSignStar1(){}

State* StateSignStar1::stateNow()
{
	if (StateSignStar1::instance == NULL)
		StateSignStar1::instance = new  StateSignStar1();
				return StateSignStar1::instance ;
}

State* StateSignStar1::work(char * letter)
{
	if (*letter == '*')
	{
		return StateSignStar2::stateNow();
	}
	else
	{
		return StateSignStar1::stateNow();
	}
}
