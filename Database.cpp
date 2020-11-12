#include "Database.h"
#include "Relation.h"
#include <string>
#include <unordered_map>
#include <sstream>

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

bool Database::updateRelation(string relName, Relation r, bool &tuplesAdded){
	relations[relName] = relations[relName].Union(r, tuplesAdded);
	//how to see if it inserted anything or not???
}
