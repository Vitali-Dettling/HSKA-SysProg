/*
 * StateSignCorner2.h
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#ifndef STATESIGNCORNER2_H_
#define STATESIGNCORNER2_H_

#include "StateSignAttention.h"

class StateSignCorner2: public StateSignAttention
{

	static StateSignCorner2* instance;

public:

	StateSignCorner2();
	virtual~StateSignCorner2();

	State* work(char *letter);

	static State* stateNow();
};

#endif /* STATESIGNCORNER2_H_ */
