#pragma once 
#include "Automaton.h"

class Comment : public Automaton {
public:
	Comment();
	int Read(const string& input);
};
