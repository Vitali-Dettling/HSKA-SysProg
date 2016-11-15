/*
 * StateStart.h
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#ifndef STATESTART_H_
#define STATESTART_H_

#include "State.h"



class StateStart:public State
{

	static StateStart* instance;

public:

	StateStart();
	virtual ~StateStart();

	static State* stateNow();
	virtual State* work(char* letter);
	virtual TType getType();

};

#endif /* STATESTART_H_ */
