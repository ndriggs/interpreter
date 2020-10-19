#include "NotAString.h"
#include <string>

NotAString::NotAString(){
	type = UNDEFINED;
}

int NotAString::Read(const string& input){
	bool state_even = false;
	newLines = 0;
	if(input[0] != '\''){
		return 0;
	}
	for(int i = 1; (unsigned)i < input.size(); i++){
		if(input[i] == '\n')
			newLines += 1;
		if(state_even){
			if(input[i] != '\'')
				return 0;
		} 
		if(input[i] == '\'')
			state_even = !state_even;
	}
	return input.size() - 1;
}
