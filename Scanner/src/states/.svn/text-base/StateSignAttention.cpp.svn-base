/*
 * StateSignAttention.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */
#include <stdlib.h>
#include "StateSignAttention.h"
#include "StateSignCorner2.h"

StateSignAttention* StateSignAttention::instance = NULL;



StateSignAttention::StateSignAttention()
{
	isStartState = false;
	isEndState = false;
	TType type = SIGNLOWER_THAN;
}
StateSignAttention::~StateSignAttention(){}

State* StateSignAttention::stateNow()
{
	if (StateSignAttention::instance == NULL)
		StateSignAttention::instance = new  StateSignAttention();
			return StateSignAttention::instance ;
}

State* StateSignAttention::work(char * letter)
{
	if (*letter =='>')
	{
		return StateSignCorner2::stateNow();
	}
	else
	{
		return StateStart::stateNow();
	}
}
