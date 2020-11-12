#include "Rule.h"
#include "Predicate.h"
#include <string>
#include <vector> 
#include <sstream>

Rule::Rule(Predicate* headPredicate){
	this->headPredicate = headPredicate;
}

void Rule::addHeadPredicate(Predicate* headPredicate){
	this->headPredicate = headPredicate;
}

void Rule::addPredicate(Predicate* p){
	predicates.push_back(p);
}

string Rule::toString(){
	stringstream ss;
	ss << headPredicate->toString() << " :- ";
	for(int i = 0; (unsigned)i < predicates.size(); i++){
		ss << predicates[i]->toString();
		if((unsigned)(i + 1) < predicates.size())
			ss << ",";
	}
	ss << ".";
	return ss.str();
}

vector<Predicate*> Rule::getPredicates() const{
	return predicates;
}

vector<Parameter*> Rule::getHeadPredParams() const{
	return headPredicate->param_vec();
}

string Rule::getHeadPredId() const{
	return headPredicate->getId();
}
