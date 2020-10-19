#pragma once
#include "Automaton.h"

class NoEndComment : public Automaton {
public:
	NoEndComment();
	int Read(const string& input);
};

