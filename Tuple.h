#pragma once 
#include <vector>
#include <string>
using namespace std;

class Tuple {
private :
	vector<string> values;

public :
	Tuple(vector<string> values);
	bool operator< (const Tuple & other) const;
	void toString() const;
	string getVal(int index) const;
	vector<string> getVals() const;	
};
