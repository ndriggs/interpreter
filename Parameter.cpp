#include "Parameter.h"
#include <string>

Parameter::Parameter(string value, bool isConst){
	this->value = value;
	isConstant = isConst;
}

void Parameter::addSome(string c){
	value += c;
}

void Parameter::addBool(bool cons){
	isConstant = cons;
}

string Parameter::toString(){
	return this->value;
}

bool Parameter::isConstant() const{
	return isConstant;
}
