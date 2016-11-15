/*
 * IScanner.h
 *
 *  Created on: 17.04.2012
 *      Author: voma1018
 */

#ifndef ISCANNER_H_
#define ISCANNER_H_

#include "ScannerImp.h"
#include "Token.h"


class IScanner
{

public:

	virtual Token nextToken()
	{
	return this->nextToken();
	}



	virtual void freeToken(Token token)
	{
		this->freeToken(token);
	}

};


#endif /* ISCANNER_H_ */
