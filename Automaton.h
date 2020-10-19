#pragma once
#include "Token.h"
using namespace std;

class Automaton{
protected:
	int newLines = 0;
	TokenType type;

public:
	Automaton(){};
	Automaton(TokenType type){ this->type = type; }
	int virtual Read(const string& input) = 0;
	virtual Token* CreateToken(string input, int lineNumber){ return new Token(type, input, lineNumber); }
	virtual int NewLinesRead() const { return newLines; }
};
