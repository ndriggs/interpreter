#pragma once
#include "Header.h"
#include "Tuple.h"
#include <set>
#include <string>
#include <vector>

using namespace std;

class Relation {
private:
	string name;
	Header header;
	set<Tuple> tuples;

public:
	Relation(string schemeName, vector<string> attrList);
	Relation();
	void addTuple(vector<string> tuple);
	void addTuples(set<Tuple> tuples);
	Relation select1(int index, string value);
	Relation select2(int index1, int index2);
	Relation project(vector<int> indices);
	Relation rename(int index, string newName);
	bool isEmpty();
	int tuple_size();
	void toString();
};
