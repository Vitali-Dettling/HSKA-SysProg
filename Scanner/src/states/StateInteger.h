/*
 * StateInteger.h
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#ifndef STATEINTEGER_H_
#define STATEINTEGER_H_

#include "StateStart.h"

class StateInteger:public StateStart
{
	static StateInteger* instance;

public:
	StateInteger();
	virtual ~StateInteger();

	State* work(char *letter);

	static State* stateNow();
};

#endif /* STATEINTEGER_H_ */
