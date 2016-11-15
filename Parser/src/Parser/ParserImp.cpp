/*
 * ParserImp.cpp
 *
 *  Created on: May 29, 2012
 *      Author: voma1018
 */
#include "ParserImp.h"
#include "stdlib.h"

ParserImp::ParserImp(char* data)
{
	myScan = new ScannerImp(data);
	parse();
}

ParserImp::~ParserImp(){}

void ParserImp::parse()
{
	getNextToken();
	if(toke != NULL)
	{
	this->makeCode = new MakeCodeOutput();
	node = new Node( makeCode );

	prog(node);													// DECLS STATEMENTS
	node->typeCheck();
	node->makeCode();

	}
	else
	{
		printf("Leerer File\n" );
	}

	int pthread_join(pthread_t th, void **thread_return);
}

void ParserImp::prog(Node* root)
{
	if (toke != NULL)						// DECLS STATEMENTS
	{
		Node* prog = root->add(PROG,NULL);

		// Bei dem Rest ist es Akzeptabel das es in den IF BAUCH geht !!
		// -- INT (--> Decls <--) -- Identifier, Print, Read, Signcurlybracket_Open, If, While (-->Statements<--)
		if(		toke->getTType() == INT
			||	toke->getTType() == IDENTIFIER
			||	toke->getTType() == PRINT
			||	toke->getTType() == READ
			||	toke->getTType() == IF
			||	toke->getTType() == WHILE
			|| 	toke->getTType() == SIGNCURLYBRACKET_OPEN)
		{
			decls(prog);
			statements(prog);
		}


		else
		{
			//Fehlerfall
			errorM();
		}
	}
	else
	{
		//Leere Datei
	}
}

void ParserImp::decls(Node* root)
{
	// DECL ; DECLS
	if(toke != NULL)
	{
		if(toke->getTType() == INT )
		{
			Node* decls_1 = root->add(DECLS_1,NULL);
			// DECL
			decl(decls_1);
			// Char ';'

			if(toke != NULL)
			{
				if(	toke->getTType() == SIGNSEMICOLON ) 				// ;
				{
					getNextToken();							// das ';' gab es und wird nächstes token verlangt
					//DECLS
					decls(decls_1);

				}
				else
				{
					//FehlerFall
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}
		}
		// EPSILON Fall für Decls, dadürch würde es bei Prog weiter gehen
		// Bedingungen sind Follow von Decls, die dem First Statements entsprechen !!
		else if	(	toke->getTType() == IDENTIFIER
				 ||	toke->getTType() == PRINT
				 ||	toke->getTType() == READ
				 ||	toke->getTType() == SIGNCURLYBRACKET_OPEN
				 ||	toke->getTType() == IF
				 ||	toke->getTType() == WHILE)
		{
			root->add(DECLS_E,NULL);
		}

		else
		{
			//Fehlerfall
			errorM();
		}
	}
	//epsilon leer
	else
	{
		root->add(DECLS_E,NULL);
	}


}

void ParserImp::decl(Node* root)
{
	if(toke != NULL)
	{
		//	int ARRAY identifier
		if(	toke->getTType() == INT )
		{
			Node* decl = root->add(DECL,NULL);
			getNextToken();

			// ARRAY
			array(decl);

			if(toke != NULL)
			{
				// Identifier
				if (toke->getTType() == IDENTIFIER )
				{
					decl->add(LEAF,toke->getKey());

					getNextToken();
				}
				else
				{
					// Fehlerfall
					errorM();
				}
			}
		}
		else
		{
			//Fehlerfall
			errorM();
		}
	}
	else
	{
		//Fehlerfall
		errorM();
	}
}

void ParserImp::array(Node* root)
{
	if(toke != NULL)
	{
		if(toke->getTType() == SIGNSQUAREBRACKET_OPEN)								// [integer]
		{																			// [
			Node* array1 = root->add(ARRAY_1,NULL);
			getNextToken();

			if(toke != NULL)
			{
				if(toke->getTType() == INTEGER)											// interger
				{
					array1->add(LEAF,toke->getKey());

					getNextToken();

					if(toke != NULL)
					{
						if(toke->getTType()== SIGNSQUAREBRACKET_CLOSE)						// ]
						{
							getNextToken();
						}
						else
						{
							//Fehlerfall
							errorM();
						}
					}
					else
					{
						//Fehlerfall
						errorM();
					}
				}
				else
				{
					// FEHLERFALL
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}
		}
		else if(toke->getTType() == IDENTIFIER)							// EPSILON
		{
			root->add(ARRAY_E,NULL);


		}
		else
		{
			//Fehlerfall
			errorM();
		}
	}
	else
	{
		root->add(ARRAY_E,NULL);
	}
}

void ParserImp::statements(Node* root)
{
	if(toke != NULL)
	{
		if(	toke->getTType() == IDENTIFIER ||												// STATEMENT ; STATEMENTS
			toke->getTType() == PRINT ||													// STATEMENT
			toke->getTType() == READ||
			toke->getTType() == SIGNCURLYBRACKET_OPEN||
			toke->getTType() == IF ||
			toke->getTType() == WHILE)
		{
			Node* statements1 = root->add(STATEMENTS_1,NULL);
			statement(statements1);

			if(toke != NULL)
			{
				if(toke->getTType() == SIGNSEMICOLON)											//  ;
				{
					getNextToken();
					statements(statements1);													// Statements
				}
				else
				{
					//Fehlerfall
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}
		}
		else if(toke->getTType() == SIGNCURLYBRACKET_CLOSE )								// EPSILON
		{
			root->add(STATEMENTS_E,NULL);
		}
		else
		{
			//Fehlerfall
			errorM();
		}
	}
	else
	{
		root->add(STATEMENTS_E,NULL);
	}
}

void ParserImp::statement(Node* root)
{
	if(toke != NULL)
	{
		//identifier index = exp
		if(toke->getTType() == IDENTIFIER)
		{
			Node* statement1 = root->add(STATEMENT_1,NULL);
			statement1->add(LEAF,toke->getKey());
			getNextToken();
			index(statement1);

			if(toke != NULL)
			{
				if(toke->getTType() == SIGNEQUAL)
				{
					getNextToken();
					exp(statement1);
				}
				else
				{
					//Fehlerfall
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}
		}
		//print (Exp)
		else if(toke->getTType() == PRINT)
		{
			Node* statement2 = root->add(STATEMENT_2,NULL);
			getNextToken();

			if(toke != NULL)
			{
				if(toke->getTType() == SIGNROUNDBRACKET_OPEN)
				{
					getNextToken();
					exp(statement2);

					if(toke!= NULL)
					{
						if(toke->getTType() == SIGNROUNDBRACKET_CLOSE)
						{
							getNextToken();
						}
						else
						{
							//Fehlerfall
							errorM();
						}
					}
					else
					{
						errorM();
					}
				}
				else
				{
					//Fehlerfall
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}

		}
		//read(identifier Index)
		else if(toke->getTType() == READ)
		{
			Node* statement3 = root->add(STATEMENT_3,NULL);
			getNextToken();

			if(toke!= NULL)
			{
				if(toke->getTType() == SIGNROUNDBRACKET_OPEN)
				{
					getNextToken();

					if(toke!= NULL)
					{
						if(toke->getTType() == IDENTIFIER)
						{
							statement3->add(LEAF,toke->getKey());
							getNextToken();
							index(statement3);

							if(toke!= NULL)
							{
								if(toke->getTType() == SIGNROUNDBRACKET_CLOSE)
								{
									getNextToken();
								}
								else
								{
									// Fehlerfall
									errorM();
								}
							}
							else
							{
								errorM();
							}
						}
						else
						{
							//Fehlerfall
							errorM();
						}
					}
					else
					{
						//Fehlerfall
					}
				}
				else
				{
					//Fehlerfall
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}
		}
		//{Statements}
		else if(toke->getTType() == SIGNCURLYBRACKET_OPEN)
		{
			Node* statement4 = root->add(STATEMENT_4,NULL);
			getNextToken();
			statements(statement4);

			if(toke != NULL)
			{
				if (toke->getTType() == SIGNCURLYBRACKET_CLOSE)
				{
					getNextToken();
				}
				else
				{
					// Fehlerfall
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}
		}
		//if (exp) statement else statement
		else if(toke->getTType() == IF)
		{
			Node* statement5 = root->add(STATEMENT_5,NULL);
			getNextToken();
			if(toke != NULL)
			{
				if(toke->getTType() == SIGNROUNDBRACKET_OPEN)
				{
					getNextToken();
					exp(statement5);

					if(toke!= NULL)
					{
						if(toke->getTType() == SIGNROUNDBRACKET_CLOSE)
						{
							getNextToken();
							statement(statement5);

							if(toke!= NULL)
							{
								if(toke->getTType() == ELSE)
								{
									getNextToken();
									statement(statement5);
								}
								else
								{
									//Fehlerfall
									errorM();
								}
							}
							else
							{
								//fehlerfall
								errorM();
							}
						}
						else
						{
							//Fehlerfall
							errorM();
						}
					}
					else
					{
						//Fehlerfall
						errorM();
					}
				}
				else
				{
					//Fehlerfall
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}
		}
		//while(exp) statement
		else if(toke->getTType() == WHILE)
		{
			Node* statement6 = root->add(STATEMENT_6,NULL);
			getNextToken();
			if(toke != NULL)
			{
				if(toke->getTType() == SIGNROUNDBRACKET_OPEN)
				{
					getNextToken();
					exp(statement6);

					if(toke!=NULL)
					{
						if(toke->getTType() == SIGNROUNDBRACKET_CLOSE)
						{
							getNextToken();
							statement(statement6);
						}
						else
						{
							// Fehlerfall
							errorM();
						}
					}
					else
					{
						//Fehlerfall
						errorM();
					}
				}
				else
				{
					// Fehlerfall
					errorM();
				}
			}
			else
			{
				// Fehlerfall
				errorM();
			}
	}
		else // irgend ein schund
		{
			// Fehlerfall
			errorM();
		}
	}
	else
	{
		//Fehlerfall
		errorM();
	}

}

void ParserImp::exp(Node* root)
{
	Node* exp = root->add(EXP,NULL);
	exp2(exp);
	op_exp(exp);
}

void ParserImp::exp2(Node* root)
{
	if(toke!= NULL)
	{
		//(exp)
		if(toke->getTType() == SIGNROUNDBRACKET_OPEN)
		{
			Node* exp2 = root->add(EXP2_1,NULL);
			getNextToken();
			exp(exp2);
			if(toke != NULL)
			{
				if (toke->getTType() == SIGNROUNDBRACKET_CLOSE)
				{
					getNextToken();
				}
				else
				{
					// Fehlerfall
					errorM();
				}
			}
			else
			{
				//Fehlerfall
				errorM();
			}
		}

		//identifier index
		else if(toke->getTType() == IDENTIFIER)
		{
			Node* exp2 = root->add(EXP2_2,NULL);
			exp2->add(LEAF,toke->getKey());

			getNextToken();
			index(exp2);
		}

		//integer
		else if (toke->getTType() == INTEGER)
		{
			Node* exp2 = root->add(EXP2_3,NULL);
			exp2->add(LEAF,toke->getKey());
			getNextToken();
		}

		// - Exp2
		else if(toke->getTType() == SIGNMINUS)
		{
			Node* exp24 = root->add(EXP2_4,NULL);
			getNextToken();
			exp2(exp24);
		}

		// ! Exp2
		else if(toke->getTType() == SIGNATTENTION)
		{
			Node* exp24 = root->add(EXP2_5,NULL);
			getNextToken();
			exp2(exp24);
		}
		else
		{
			//Fehlerfall

						errorM();
		}
	}
	else
	{
		//fehlerfall
		errorM();
	}
}

void ParserImp::index(Node* root)
{
	if(toke!= NULL)
	{
		// [exp]
		if(toke->getTType() == SIGNSQUAREBRACKET_OPEN)
		{
			Node* index = root->add(INDEX_1,NULL);
			getNextToken();
			exp(index);

			if(toke!= NULL)
			{
				if(toke->getTType() == SIGNSQUAREBRACKET_CLOSE)
				{
					getNextToken();
				}
				else
				{
					// Fehlerfall
					errorM();
				}
			}
			else
			{
				//fehlerfall
				errorM();
			}
		}

		// epsilon
		else if (	toke->getTType() == SIGNEQUAL
				||	toke->getTType() == SIGNROUNDBRACKET_CLOSE
				||	toke->getTType() == SIGNPLUS
				||	toke->getTType() == SIGNMINUS
				||	toke->getTType() == SIGNSTAR
				||	toke->getTType() == SIGNSLASH
				||	toke->getTType() == SIGNLOWER_THAN
				||	toke->getTType() == SIGNHIGHER_THAN
				||	toke->getTType() == SIGNCOMPLEX
				||	toke->getTType() == SIGNAND
				||	toke->getTType() == SIGNSEMICOLON
				||	toke->getTType() == ELSE
				||	toke->getTType() == SIGNSQUAREBRACKET_CLOSE	 )
		{
			root->add(INDEX_E,NULL);
		}
		else
		{
			// Fehlerfall

			errorM();

		}
	}
	else
	{
		root->add(INDEX_E,NULL);
	}
}

void ParserImp::op_exp(Node* root)
{
	if(toke != NULL)
	{
		//op exp
		if(		toke->getTType() == SIGNEQUAL
			||	toke->getTType() == SIGNPLUS
			||	toke->getTType() == SIGNMINUS
			||	toke->getTType() == SIGNSTAR
			||	toke->getTType() == SIGNSLASH
			||	toke->getTType() == SIGNLOWER_THAN
			||	toke->getTType() == SIGNHIGHER_THAN
			||	toke->getTType() == SIGNCOMPLEX
			||	toke->getTType() == SIGNAND)
		{
			Node* op_exp = root->add(OP_EXP_1,NULL);
			op(op_exp);
			exp(op_exp);

		}

		// epsilon
		else if(	toke->getTType() == SIGNSEMICOLON
				||	toke->getTType() == ELSE
				||	toke->getTType() == SIGNROUNDBRACKET_CLOSE
				||	toke->getTType() == SIGNSQUAREBRACKET_CLOSE)
		{
			root->add(OP_EXP_E,NULL);
		}
		else
		{
			//fehlerfall
			errorM();
		}
	}
	else
	{
		root->add(OP_EXP_E,NULL);
	}
}

void ParserImp::op(Node* root)
{
	if(toke != NULL)
	{
		if(	toke->getTType() == SIGNEQUAL)
		{
			root->add(OP_EQUAL,NULL);
		}
		else if(toke->getTType() == SIGNPLUS)
		{
			root->add(OP_PLUS,NULL);
		}
		else if(toke->getTType() == SIGNMINUS)
		{
			root->add(OP_MINUS,NULL);
		}
		else if(toke->getTType() == SIGNSTAR)
		{
			root->add(OP_MULT,NULL);
		}
		else if(toke->getTType() == SIGNSLASH)
		{
			root->add(OP_DIV,NULL);
		}
		else if(toke->getTType() == SIGNLOWER_THAN)
		{
			root->add(OP_LESS,NULL);
		}
		else if(toke->getTType() == SIGNHIGHER_THAN)
		{
			root->add(OP_GREATER,NULL);
		}
		else if (toke->getTType() == SIGNCOMPLEX)
		{
			root->add(OP_UNEQUAL,NULL);
		}
		else if(toke->getTType() == SIGNAND)
		{
			root->add(OP_AND,NULL);
		}
		else
		{
			//Fehlerfall
			errorM();
		}
		getNextToken();
	}
	else
	{
		//fehlerfall
		errorM();
	}
}

void ParserImp::errorM()
{
	printf("Es wurde ein syntaktischer Fehler erkannt!");

	node->treeDelete();
	exit(-1);
}

void ParserImp::getNextToken()
{

	this->toke = myScan->nextToken();

	if(toke!= NULL)
	{
		while(toke->getTType() == COMMENT  )
		{

			this->toke = myScan->nextToken();

		}
	}
}
