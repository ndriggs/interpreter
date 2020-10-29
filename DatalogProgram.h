#pragma once
#include <set>
#include <string>
#include "Predicate.h"
#include <vector>
#include "Rule.h"
using namespace std;

class DatalogProgram {
private:
	vector<Predicate*> schemes;
	vector<Predicate*> facts;
	vector<Predicate*> queries;
	vector<Rule*> rules;
	set<string> domain;
public:
	void insertDomainString(string str);
	void addScheme(Predicate* scheme);
	void addFact(Predicate* fact);
	void addQuery(Predicate* query);
	void addRule(Rule* rule);
	string toString();
	vector<Predicate*> getSchemes();
	vector<Predicate*> getFacts();
	vector<Predicate*> getQueries();
	vector<Rule*> getRules();

};
