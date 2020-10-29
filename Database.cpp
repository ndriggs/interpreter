#include "Database.h"
#include "Relation.h"
#include <string>
#include <unordered_map>

using namespace std;

void Database::addRelation(string name, Relation r){
	relations.insert({name, r});
}

void Database::addTuple(string name, vector<string> tupl){
	relations.at(name).addTuple(tupl);
}
