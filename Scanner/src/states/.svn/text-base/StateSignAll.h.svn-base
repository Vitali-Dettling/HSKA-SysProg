/*
 * StateSignAll.h
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#ifndef STATESIGNALL_H_
#define STATESIGNALL_H_

#include "StateStart.h"

class StateSignAll:public StateStart
{
	static StateSignAll* instance;

public:
	StateSignAll();
	virtual ~StateSignAll();

	TType getType(char * letter);
	State* work(char *letter);
	static State* stateNow();
	void setType(TType);

};

#endif /* STATESIGNALL_H_ */
