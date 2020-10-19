#include "Tuple.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
	vector<string> s;
	s.push_back("a");
	s.push_back("b");
	Tuple t(s);
	
	return 0;

}
