#include "Parameter.h"
#include <string>

Parameter::Parameter(string value, bool isConst){
	this->value = value;
	isString = isConst;
}

void Parameter::addSome(string c){
	value += c;
}

void Parameter::addBool(bool cons){
	isString = cons;
}

string Parameter::toString(){
	return this->value;
}

bool Parameter::isConstant(){
	return isString;
}
