/*
 * State.h
 *
 *  Created on: 07.04.2012
 *      Author: voma1018
 */

#ifndef STATE_H_
#define STATE_H_


#include "../TType.h"

class State
{
protected:

	TType type;

public:

	bool isStartState, isEndState;

	State();
	virtual ~State();

	virtual TType getType();

	/*
	 *
	 *
	 * */
	virtual State* work(char* letter)= 0;

};

#endif /* STATE_H_ */
