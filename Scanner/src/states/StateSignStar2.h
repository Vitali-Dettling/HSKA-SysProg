/*
 * StateSignStar2.h
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#ifndef STATESIGNSTAR2_H_
#define STATESIGNSTAR2_H_

#include "StateSignStar1.h"

class StateSignStar2: public StateSignStar1
{
	static StateSignStar2* instance;

public:
	StateSignStar2();
	virtual~StateSignStar2();

	State* work(char *letter);

	static State* stateNow();
};

#endif /* STATESIGNSTAR2_H_ */
