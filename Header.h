#pragma once
#include <vector> 
#include <string>

using namespace std;

class Header {
private :
	vector<string> attributes;

public :
	Header();
	Header(vector<string> attr);
	void toString();
	int size();
	string print_attribute(int index);
	vector<string> getAtt();
};
