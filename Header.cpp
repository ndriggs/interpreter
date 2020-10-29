#include "Header.h"
#include <vector>
#include <string>

using namespace std;

Header::Header(){}

Header::Header(vector<string> attr){
	this->attributes = attr;
}
