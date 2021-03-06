#pragma once
#include "Relation.h"
#include <unordered_map>
#include <string>

using namespace std;

class Database {
private:
	unordered_map<string, Relation> relations;
public:
	void addRelation(string name, Relation r);
	void addTuple(string name, vector<string> tupl);
	void toString();
	Relation getRelation(string name) const;
	void updateRelation(string relName, Relation r, bool &tuplesAdded);
	unordered_map<string, Relation> getRelations() const;
	int num_tuples() const;
};
