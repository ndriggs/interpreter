#pragma once
#include "Automaton.h"

class NotAString : public Automaton {
public:
	NotAString();
	int Read(const string& input);
};
