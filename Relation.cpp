#include "Relation.h"
#include "Tuple.h"
#include "Header.h"
#include <string>
#include <vector>
#include <set>

using namespace std;

Relation::Relation(string schemeName, vector<string> attrList){
	this->name = schemeName;
	Header header(attrList);
}

void Relation::addTuple(vector<string> tuple){
	Tuple t(tuple);
	tuples.insert(t);
}

Relation Relation::select1(Relation r, int index, string value){
	return r;
}

Relation Relation::select2(Relation r, int index1, int index2){
	return r;
}

Relation Relation::project(Relation r, vector<string> indices){
	return r;
}

Relation rename(Relation r){
	return r;
}
