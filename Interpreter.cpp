#include "Interpreter.h"
#include "DatalogProgram.h"
#include "Database.h"
#include "Predicate.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
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
	/***
	cout << endl << "Database:" << endl;
	db->toString();***/

	//for each query
	//get the relation with the same name as the predicate name of the query
	//select tuples that match the query
	//project
	//rename
		
	vector<Predicate*> queries = dp->getQueries();
	for(int i = 0; (unsigned)i < queries.size(); i++){
		string name = queries[i]->getId();
		Relation r = db->getRelation(name);
		vector<Parameter*> params = queries[i]->param_vec();
		vector<int> var_indexs;
		vector<string> var_names;
		for(int i = 0; (unsigned)i < params.size(); i++){
			if(params[i]->isConstant()){
				r = r.select1(i, params[i]->toString());
			} else {
				vector<string>::iterator it = find(var_names.begin(), var_names.end(), params[i]->toString());
				if(it != var_names.end()){
					r = r.select2(i, var_indexs[it - var_names.begin()]);
				} else {
					var_indexs.push_back(i);
					var_names.push_back(params[i]->toString());
				}
			}
		}
		r = r.project(var_indexs);
		r = r.rename(var_names);
		cout << queries[i]->toString() << "? ";
		if(r.isEmpty())
			cout << "No" << endl;
		else{
			cout << "Yes(" << r.tuple_size() << ")" << endl;
			if(r.header_size() > 0)
				r.toString();
		}
	}
}


Relation* Interpreter::evaluatePredicate(Predicate* p){
	string name = p->getId();
	vector<string> params = p->param_toString();
	Relation* r = new Relation(name, params);
	return r;
}
