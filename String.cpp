#include "String.h"
#include <string>

String::String(){
	type = STRING;
}

int String::Read(const string& input){
	newLines = 0;
	bool state_even = false;
	if(input[0] != '\''){
		return 0;
	}
	for(int i = 1; (unsigned)i < input.size(); i++){
		if(input[i] == '\n')
			newLines += 1;	
		if(state_even){
			if(input[i] != '\''){
				if(input[i] == '\n')
					newLines -= 1;	
				return i;
			}
		}
		if(input[i] == '\''){
			state_even = !state_even;
		}
	}
	return 0;
}

