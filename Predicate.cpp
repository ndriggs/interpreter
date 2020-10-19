#include "Predicate.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

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
