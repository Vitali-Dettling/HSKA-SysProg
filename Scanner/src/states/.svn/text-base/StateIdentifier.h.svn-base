/*
 * StateIdentifier.h
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#ifndef STATEIDENTIFIER_H_
#define STATEIDENTIFIER_H_

#include "StateStart.h"


class StateIdentifier:public StateStart
{
	static StateIdentifier* instance;

public:
	StateIdentifier();
	virtual ~StateIdentifier();

	State* work(char * letter);
	static State* stateNow();
	TType getType();

};

#endif /* STATEIDENTIFIER_H_ */
