#include "EndOfFile.h"
#include <string>

EndOfFile::EndOfFile(){
	type = END_OF_FILE;
}

int EndOfFile::Read(const string& input){
	if(input.size() == 0){ // need to make sure input is an ifstream
		return 1;
	} else {
		return 0;
	}
}
