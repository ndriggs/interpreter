#include "MatcherAutomaton.h"

using namespace std;

MatcherAutomaton::MatcherAutomaton(string toMatch, TokenType type) {
	this->toMatch = toMatch;
	this->type = type;
}

int MatcherAutomaton::Read(const string& input) {
	bool isMatch = true;
	int inputRead = 0;
	for (int i = 0; i < (int)toMatch.size() && isMatch; i++) {
		if (input[i] != toMatch[i]) {
			isMatch = false;
		}
	}
	if (isMatch) {
		inputRead = toMatch.size();
	}
	return inputRead;
}
