#pragma once
#include <string>
using namespace std;

class Parameter {
private:
	string value;
	bool isString;	
public:
	Parameter(){}
	Parameter(string value, bool isConst);
	void addSome(string c);
	string toString();
	void addBool(bool cons);
	bool isConstant();
};
