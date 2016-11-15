/*
 * StateSignStar2.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */
#include <stdlib.h>
#include "StateSignStar2.h"
#include "StateSignStar1.h"
#include "StateSignSlash2.h"

StateSignStar2* StateSignStar2::instance = NULL;

StateSignStar2::StateSignStar2()
{
	isStartState = false;
	isEndState = false;
	type = SIGNSLASH;
}
StateSignStar2::~StateSignStar2(){}

State* StateSignStar2::stateNow()
{
	if (StateSignStar2::instance == NULL)
		StateSignStar2::instance = new  StateSignStar2();
		return StateSignStar2::instance ;
}

State* StateSignStar2::work(char * letter)
{
	if(*letter == '/')
	{
		return StateSignSlash2::stateNow();
	}
	else if (*letter == '*')
	{
		return StateSignStar2::stateNow();
	}
	else
	{

		return StateSignStar1::stateNow();
	}
}
