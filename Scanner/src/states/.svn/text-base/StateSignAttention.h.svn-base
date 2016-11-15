/*
 * StateSignAttention.h
 *
 *  Created on: Apr 4, 2012
 *      Author: voma1018
 */

#ifndef STATESIGNATTENTION_H_
#define STATESIGNATTENTION_H_

#include "StateSignCorner1.h"

class StateSignAttention: public StateSignCorner1 {

	static StateSignAttention* instance;


public:
	StateSignAttention();
	~StateSignAttention();

	State* work(char *letter);

	static State* stateNow();
};

#endif /* STATESIGNATTENTION_H_ */
