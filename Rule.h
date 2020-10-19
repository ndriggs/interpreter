#pragma once
#include <string>
#include "Predicate.h"
#include <vector>
using namespace std;

class Rule {
private:
	Predicate* headPredicate;
	vector<Predicate*> predicates;
public:
	Rule(Predicate* headPredicate);
	void addHeadPredicate(Predicate* headPredicate);
	void addPredicate(Predicate* p);
	string toString();

};
