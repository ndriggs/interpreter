#pragma once
#include "Automaton.h"

using namespace std;

class MatcherAutomaton : public Automaton 
{
private:
	string toMatch;

public:
	MatcherAutomaton(){};
	MatcherAutomaton(string toMatch, TokenType type); //before also had TokenType type
	virtual int Read(const string& input);
};

