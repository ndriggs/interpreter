#pragma once
#include "Automaton.h"

class String : public Automaton {
public:
	String();
	int Read(const string& input);
};

