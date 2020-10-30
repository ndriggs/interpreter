#include "Header.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Header::Header(){}

Header::Header(vector<string> attr){
	this->attributes = attr;
}

void Header::toString(){
	for(int i = 0; (unsigned)i < attributes.size(); i++){
		cout << attributes[i] << "  ";
	}
	cout << endl;
} 

vector<string> Header::getAtt(){
	return attributes;
}
