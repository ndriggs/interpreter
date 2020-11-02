#include "Relation.h"
#include "Tuple.h"
#include "Header.h"
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

Relation::Relation(string schemeName, vector<string> attrList){
	this->name = schemeName;
	header = Header(attrList);
}

Relation::Relation(){
	name="";
}

void Relation::addTuple(vector<string> tuple){
	Tuple t(tuple);
	tuples.insert(t);
}

void Relation::addTuples(set<Tuple> tuples){
	this->tuples = tuples;
}

Relation Relation::select1(int index, string value){ 
	Relation rel;
	set<Tuple> newTuples;
	for(auto it = tuples.begin(); it != tuples.end(); it++){
		if(it->getVal(index) == value)
			newTuples.insert(*it);
	}
	rel.addTuples(newTuples);
	return rel;
}

Relation Relation::select2(int index1, int index2){
	Relation rel;
	set<Tuple> newTuples;
	for(auto it = tuples.begin(); it != tuples.end(); it++){
		if(it->getVal(index1) == it->getVal(index2))
			newTuples.insert(*it);
	}
	rel.addTuples(newTuples);
	return rel;
}

Relation Relation::project(vector<int> indices){
	Relation rel; 
	set<Tuple> newTuples;
	for(auto it = tuples.begin(); it != tuples.end(); it++){
		vector<string> tup = it->getVals();
		vector<string> newTup;
       		for(int i = 0; (unsigned)i < indices.size(); i++)
			newTup.push_back(tup[indices[i]]);
		newTuples.insert(newTup);
	}
	rel.addTuples(newTuples);
	return rel;
}

bool Relation::isEmpty(){
	if(tuples.size() == 0)
		return true;
	else 
		return false;
}

int Relation::tuple_size(){
	return tuples.size();
}

Relation Relation::rename(int index, string newName){
	vector<string> newNames = header.getAtt();
	newNames[index] = newName;
	Relation rel(name, newNames);
	return rel;
}

void Relation::toString(){
	for(auto it = tuples.begin(); it != tuples.end(); ++it){
		for(int i = 0; (unsigned)i < header.size(); i++){
			cout << "  " << header.print_attribute(i);
			cout << "=" << it->getVal(i);
			if(((unsigned)i + 1) < header.size())
				cout << ", ";
		}
		cout << endl;
	}
}
