#pragma once 
#include "Token.h"
#include "Automaton.h"
#include "MatcherAutomaton.h"
#include "Comment.h"
#include "EndOfFile.h"
#include "Identity.h"
#include "NoEndComment.h"
#include "NotAString.h"
#include "String.h"
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Lexer {
	private:
		vector<Token> tokens;
		vector<Automaton*> machines;
	public:
		Lexer();
		void addToken(Token tolkien);
		void Run(string input);
		string print();
};
