#include "Parameter.h"
#include <string>

Parameter::Parameter(string value){
	this->value = value;
}

void Parameter::addSome(string c){
	value += c;
}

string Parameter::toString(){
	return this->value;
}
