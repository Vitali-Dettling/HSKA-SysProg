
/*
 * Scanner.h
 *
 *  Created on: Apr 6, 2012
 * 		Author: voma1018
 *
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "Token.h"
#include "TType.h"

class Scanner
{

public:

	virtual void setComment(bool) = 0;
	virtual Token* mkToken(TType type) = 0;
	virtual void ungetChar(int count) = 0;
	virtual void stop() = 0 ;

};

#endif
