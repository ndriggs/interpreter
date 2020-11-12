#include "Tuple.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Tuple::Tuple(vector<string> values){
	this->values = values;
}

bool Tuple::operator< (const Tuple & other) const {
	if(this->values < other.values)
		return true;
	else 
		return false;
}

void Tuple::toString() const{
	for(int i = 0; (unsigned)i < values.size(); i++)
		cout << values[i] << "  ";
	cout << endl;
}

string Tuple::getVal(int index) const{
	return values[index];
}

int Tuple::size() const{
	return values.size();
}

vector<string> Tuple::getVals() const{
	return values;
}
