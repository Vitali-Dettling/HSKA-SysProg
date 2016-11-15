/*
 * StateSignCorner1.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */
#include <stdlib.h>
#include "StateSignCorner1.h"
#include "StateSignAttention.h"

StateSignCorner1::StateSignCorner1()
{
	isStartState = false;
	isEndState = true;
	type = SIGNLOWER_THAN;
}

StateSignCorner1::~StateSignCorner1(){}

StateSignCorner1* StateSignCorner1::instance = NULL;


State* StateSignCorner1::stateNow()
{
	if (StateSignCorner1::instance == NULL)
		StateSignCorner1::instance = new  StateSignCorner1();
		return StateSignCorner1::instance ;
}
State* StateSignCorner1::work(char * letter)
{
	if (*letter == '!')
		return StateSignAttention::stateNow();
	else

		return StateStart::stateNow();
}
