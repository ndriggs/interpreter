#include "DatalogProgram.h"
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
void DatalogProgram::insertDomainString(string str){
	domain.insert(str);
}

void DatalogProgram::addScheme(Predicate* scheme){
	schemes.push_back(scheme);
}

void DatalogProgram::addFact(Predicate* fact){
	facts.push_back(fact);
}

void DatalogProgram::addQuery(Predicate* query){
	queries.push_back(query);
}

void DatalogProgram::addRule(Rule* rule){
	rules.push_back(rule);
}

string DatalogProgram::toString(){
	stringstream ss;
	ss << "Schemes(" << schemes.size() << "):" << endl;
	for(int i = 0; (unsigned)i < schemes.size(); i++){
		ss << "  " << schemes[i]->toString() << endl;
	}
	ss << "Facts(" << facts.size() << "):" << endl;
	for(int i = 0; (unsigned)i < facts.size(); i++){
		ss << "  " << facts[i]->toString() << "." << endl;
	}
	ss << "Rules(" << rules.size() << "):" << endl;
	for(int i = 0; (unsigned)i < rules.size(); i++){
		ss << "  " << rules[i]->toString() << endl;
	}
	ss << "Queries(" << queries.size() << "):" << endl;
	for(int i = 0; (unsigned)i < queries.size(); i++){
		ss << "  " << queries[i]->toString() << "?" << endl;
	}
	
	ss << "Domain(" << domain.size() << "):" << endl;
	set<string>::iterator it = domain.begin();
	while(it != domain.end()){
		ss << "  " << *it << endl;
		it++;
	}
	string parsed = ss.str();
	parsed.pop_back();
	return parsed;
}
