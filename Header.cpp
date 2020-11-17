#include "Header.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Header::Header(){}

Header::Header(vector<string> attr){
	this->attributes = attr;
}

string Header::print_attribute(int index){
	if(attributes.size() != 0)
		return attributes[index];
	else 
		return "";
}

void Header::toString(){
	for(int i = 0; (unsigned)i < attributes.size(); i++){
		cout << attributes[i] << "  ";
	}
	cout << endl;
}

int Header::size(){
	return attributes.size();
}

vector<string> Header::getAtt(){
	return attributes;
}
