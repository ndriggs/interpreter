#include "Interpreter.h"
#include "DatalogProgram.h"
#include "Database.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void Interpreter::Run(DatalogProgram* dp, Database* &db){
	// for every s in scheme, make a new relation
	vector<Predicate*> schemes = dp->getSchemes();
	for(int i = 0; (unsigned)i < schemes.size(); i++){
		string name = schemes[i]->getId();
		Relation* rel = evaluatePredicate(schemes[i]);
		db->addRelation(name, *rel);
	}
	//for every f in facts, make a tuple and add it to the right relation
	vector<Predicate*> facts = dp->getFacts();
	for(int i = 0; (unsigned)i < facts.size(); i++){
		string name = facts[i]->getId();
		vector<string> tupl = facts[i]->param_toString();
		db->addTuple(name, tupl);
	}
}

Relation* Interpreter::evaluatePredicate(Predicate *p){
	string name = p->getId();
	vector<string> params = p->param_toString();
	Relation* r = new Relation(name, params);
	return r;
}
