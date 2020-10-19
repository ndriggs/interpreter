#include "Comment.h"
#include <string>
#include <sstream>

Comment::Comment(){
	type = COMMENT;
}

int Comment::Read(const string& input){
	int inputRead = 0;
	newLines = 0;
	if(input[0] != '#'){
		return 0;
	}
	if(input[1] == '|'){
		for(int i = 2; (unsigned)i < input.size(); i++){
			if(input[i] == '\n')
				newLines += 1;
			if((input[i] == '|') && (input[i+1] == '#')){
				inputRead = i + 2; 
				return inputRead;
			}
		}
		return 0; //started with #| but never found an end
	}
	else {
		istringstream iss(input);
		string line;
		getline(iss, line);
		return line.size();
	}
}
		
