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
	return attributes[index];
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
