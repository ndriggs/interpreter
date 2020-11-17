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
	void addName(string name);
	void addTuple(vector<string> tuple);
	void addTuples(set<Tuple> tuples);
	Relation select1(int index, string value);
	Relation select2(int index1, int index2);
	Relation project(vector<int> indices);
	Relation rename(vector<string> newNames);
	Relation naturalJoin(Relation r);
	Relation Union(Relation r, bool &tuplesAdded);
	bool isEmpty();
	int tuple_size() const;
	void toString();
	int header_size();
	set<Tuple> getTuples();
	vector<string> getAttr();
};
