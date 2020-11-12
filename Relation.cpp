#include "Relation.h"
#include "Tuple.h"
#include "Header.h"
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

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

Relation Relation::rename(vector<string> newNames){
	Relation rel(name, newNames);
	rel.addTuples(tuples);
	return rel;
}

vector<string> Relation::getAttr(){
	return header.getAtt();
}

Relation Relation::Union(Relation r, bool &tuplesAdded){
	Relation rel(name, header.getAtt());
	set<Tuple> tuples2 = r.getTuples();
	set<Tuple> newTuples;
	for(set<Tuple>::iterator tuple1 = tuples.begin(); tuple1 != tuples.end(); tuple1++){
		for(set<Tuple>::iterator tuple2 = tuples2.begin(); tuple2 != tuples2.end(); tuple2++){
			if(tuple1->getVals() == tuple2->getVals()){
				Tuple t(tuple1->getVals());
				bool added = newTuples.insert(t).second;
				if(added)
					tuplesAdded = added;
			}
		}
	}
	rel.addTuples(newTuples);
	return rel;
}


Relation Relation::naturalJoin(Relation r){
	//check which header elements are the same
	vector<string> attr1 = header.getAtt();
	vector<string> attr2 = r.getAttr();
	vector<vector<int> > matchingAttr;
	vector<int> indexes;
	cout << "nj point 5" << endl;
	for(int i = 0; (unsigned)i < attr1.size(); i++){
		for(int j = 0; (unsigned)j < attr2.size(); j++){
			if(attr1[i] == attr2[j]){
				vector<int> pair{ i, j };
				cout << "natural j 1" << endl;
				indexes.push_back(j);
				matchingAttr.push_back(pair);
				break;
			}
		}
	}
	bool fakeBool = false;	
	if((indexes.size() == attr1.size()) && (indexes.size() == attr2.size()))
		return this->Union(r, fakeBool);

	set<Tuple> tuples2 = r.getTuples();
	set<Tuple> newTuples;
	cout << "nj 2" << endl;
	
	for(set<Tuple>::iterator tuple1 = tuples.begin(); tuple1 != tuples.end(); tuple1++){
		for(set<Tuple>::iterator tuple2 = tuples2.begin(); tuple2 != tuples2.end(); tuple2++){
			bool match = true;
			for(int k = 0; (unsigned)k < matchingAttr.size(); k++){
				if(tuple1->getVal(matchingAttr[k][0]) != tuple2->getVal(matchingAttr[k][1])){
					match = false;
					break;
				}
			}
			cout << "nj 3" << endl; 
			if(match){
				vector<string> newTuple;
				for(int i = 0; (unsigned)i < tuple1->size(); i++)
					newTuple.push_back(tuple1->getVal(i));
				for(int j = 0; (unsigned)j < tuple2->size(); j++){
					if(find(indexes.begin(), indexes.end(), j) != indexes.end())
						continue;
					newTuple.push_back(tuple2->getVal(j));
				}
				Tuple t(newTuple);
				newTuples.insert(t);
			}

		}
	}
	cout << "nj 4" << endl;
	vector<string> newHeader{ header.getAtt() };
	vector<string> rel2_attr = r.getAttr();
	for(int j = 0; (unsigned)j < r.header_size(); j++){
		if(find(indexes.begin(), indexes.end(), j) != indexes.end())
			continue;
		newHeader.push_back(rel2_attr[j]);
	}
	Relation rel(name, newHeader);
	rel.addTuples(newTuples);
	return rel;
}

set<Tuple> Relation::getTuples(){
	return tuples;
}


void Relation::toString(){
	for(auto it = tuples.begin(); it != tuples.end(); ++it){
		cout << "  ";
		for(int i = 0; i < header.size(); i++){
			cout << header.print_attribute(i);
			cout << "=" << it->getVal(i);
			if((i + 1) < header.size())
				cout << ", ";
		}
		cout << endl;
	}
}

int Relation::header_size(){
	return header.size();
}
