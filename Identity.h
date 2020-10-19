#pragma once
#include "Automaton.h"

class Identity : public Automaton {
public:
	Identity();	
	int Read(const string& input);
};
