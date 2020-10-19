#include "NoEndComment.h"
#include <string>
#include <iostream>
NoEndComment::NoEndComment(){
	type = UNDEFINED;
	newLines = 0;
}

int NoEndComment::Read(const string& input){
	if(input.substr(0,2) != "#|"){
		return 0;
	}
	for(int i = 2; (unsigned)i < input.size(); i++){
		if(input[i] == '\n')
			newLines += 1;
		if(input.substr(i,2) == "|#")
			return 0;
	}
	return input.size() - 1;
}


