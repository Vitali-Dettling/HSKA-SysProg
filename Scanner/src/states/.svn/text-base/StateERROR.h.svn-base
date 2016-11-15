/*
 * StateERROR.h
 *
 *  Created on: May 7, 2012
 *      Author: voma1018
 */

#ifndef STATEERROR_H_
#define STATEERROR_H_

#include "StateStart.h"


class StateERROR: public StateStart
{
	static StateERROR* instance;

public:
	StateERROR();
	virtual ~StateERROR();

	State* work(char * letter);
	static State* stateNow();
	TType getType();

};

#endif /* STATEERROR_H_ */
