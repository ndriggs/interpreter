#include "Database.h"
#include "Relation.h"
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

void Database::addRelation(string name, Relation r){
	relations.insert({name, r});
}

void Database::addTuple(string name, vector<string> tupl){
	relations.at(name).addTuple(tupl);
}

void Database::toString(){
	for (auto x : relations)
		x.second.toString();
}

Relation Database::getRelation(string name) const{
	return relations.at(name);
}

void Database::updateRelation(string relName, Relation r, bool &tuplesAdded){
	relations[relName] = relations[relName].Union(r, tuplesAdded); 
}

unordered_map<string, Relation> Database::getRelations() const{
	return relations;
}

int Database::num_tuples() const{
	int num_tuples = 0;
	for(auto it = relations.begin(); it != relations.end(); it++){
		num_tuples += it->second.tuple_size();
	}
	return num_tuples;
}
	
