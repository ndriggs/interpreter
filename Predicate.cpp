#include "Predicate.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string Predicate::getId(){
	return id;
}

vector<Parameter*> Predicate::param_vec(){
	return parameters;
}

vector<string> Predicate::param_toString(){
	vector<string> par;
	for(int i = 0; (unsigned)i < parameters.size(); i++){
		par.push_back(parameters[i]->toString());
	}
	return par;
}

Predicate::Predicate(){
	this->id = "";
}

Predicate::Predicate(string id){
	this->id = id;
}

void Predicate::addId(string id){
	this->id = id;
}

void Predicate::addParameter(Parameter* p){
	parameters.push_back(p);
}

string Predicate::toString(){
	stringstream ss;
	ss << id << "(";
	for(int i = 0; (unsigned)i < parameters.size(); i++){
		ss << parameters[i]->toString();
		if((unsigned)(i+1) < parameters.size())
			ss << ",";
	}
	ss << ")";
	return ss.str();
}
