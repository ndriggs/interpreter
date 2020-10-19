#pragma once
#include "Automaton.h"

class EndOfFile : public Automaton {
public:
	EndOfFile();
	int Read(const string& input);
};

