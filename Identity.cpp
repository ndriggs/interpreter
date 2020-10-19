#include "Identity.h"
#include <string>

Identity::Identity(){
	type = ID;
}

int Identity::Read(const string& input){
	if(!isalpha(input[0])){
		return 0;
	}
	for(int i = 1; (unsigned)i < input.size(); i++){
		if((!isalpha(input[i])) && (!isdigit(input[i]))){
			return i;
		}
	}
	return 0;
}
