#pragma once
#include <string>
#include <vector>
#include "Parameter.h"
using namespace std;

class Predicate {
private:
	string id;
	vector<Parameter*> parameters;
public:
	Predicate();
	Predicate(string id);
	void addId(string id);
	void addParameter(Parameter* p);
	string toString();
};
