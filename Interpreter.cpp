#include "Interpreter.h"
#include "DatalogProgram.h"
#include "Database.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void Interpreter::Run(DatalogProgram* dp, Database* db){
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
	cout << endl << "Database:" << endl;
	db->toString();

	//for each query
	//get the relation with the same name as the predicate name of the query
	//select tuples that match the query
	//project
	//rename
	
	vector<Predicate*> queries = dp->getQueries();
	for(int i = 0; (unsigned)i < queries.size(); i++){
		string name = queries[i]->getId();
		Relation r = db->getRelation(name);
		vector<string> params = queries[i]->toString();
		map<string, int> indexes;	
		for(int i = 0; (unsigned)i < params.size(); i++){
			if(params[i].isConstant()){
				r = r.select1(i, params[i].toString());
			} else {
				if(indexes.find(params[i].toString() != indexes.end()){
					rNew = r.select2();
				} else {
					indexes.insert({params[i].toString(), i});
				}
			}
		r = r.project();
		r = r.rename();
		r.toString();
		}
	}
}


Relation* Interpreter::evaluatePredicate(Predicate *p){
	string name = p->getId();
	vector<string> params = p->param_toString();
	Relation* r = new Relation(name, params);
	return r;
}
