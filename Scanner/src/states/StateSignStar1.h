/*
 * StateSignStar1.h
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#ifndef STATESIGNSTAR1_H_
#define STATESIGNSTAR1_H_

#include "StateSignSlash1.h"

class StateSignStar1: public StateSignSlash1
{
	static StateSignStar1* instance;

public:
	StateSignStar1();
	~StateSignStar1();

	State* work(char *letter);

	static State* stateNow();
};

#endif /* STATESIGNSTAR1_H_ */
