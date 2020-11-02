#include "Interpreter.h"
#include "DatalogProgram.h"
#include "Database.h"
#include "Predicate.h"
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
	cout << "got the querires" << endl;
	for(int i = 0; (unsigned)i < queries.size(); i++){
		string name = queries[i]->getId();
		cout << "got id" << endl;
		Relation r = db->getRelation(name);
		cout << "got relation" << endl;
		vector<Parameter*> params = queries[i]->param_vec();
		cout << "got param vec" << endl;
		map<string, int> indexes;	
		for(int i = 0; (unsigned)i < params.size(); i++){
			if(params[i]->isConstant()){
				r = r.select1(i, params[i]->toString());
				cout << "did select 1" << endl; 
			} else {
				if(indexes.find(params[i]->toString()) != indexes.end()){
					r = r.select2(i, indexes.find(params[i]->toString())->second);
				} else {
					indexes.insert({params[i]->toString(), i});
				}
			}
		}
		vector<int> var_indexs;
		vector<string> var_names;
		cout << "does it" << endl;
		for(auto it = indexes.begin(); it != indexes.end(); ++it){
			var_indexs.push_back(it->second);
			var_names.push_back(it->first);
		}
		cout << "like auto" << endl;
		r = r.project(var_indexs);
		cout << "how about project" << endl;
		/***for(int i = 0; (unsigned)i < var_names.size(); i++){
			r = r.rename(i, var_names[i]);
			cout << "RENAME" << endl;
		}***/
		cout << queries[i]->toString() << "?";
		if(r.isEmpty())
			cout << "No" << endl;
		else{
			cout << "Yes(" << r.tuple_size() << ")" << endl;
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
