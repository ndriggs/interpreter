#include "Parser.h"
#include "Token.h"
#include "Comment.h"
#include "NoEndComment.h"
#include "EndOfFile.h"
#include "String.h"
#include "NotAString.h"
#include "Lexer.h"
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include "DatalogProgram.h"
#include "Interpreter.h"
#include "Database.h"

using namespace std;

int main(int argc, char** argv){
	queue<string> lines;
	ifstream input_file(argv[1]);
	string line;
	string input;
	while(getline(input_file, line)){
		input += line;
		input.push_back('\n');
	}
	input.push_back(EOF);
	Lexer l;
	l.Run(input);
	ofstream outfile("newtokens.txt");
	outfile << l.print();
	outfile.close();
	ifstream tokens("newtokens.txt");
	string tokenline;
	while(!tokens.eof()){
		getline(tokens, tokenline);
		lines.push(tokenline);
	}
	Parser p;
	DatalogProgram dp = p.ParseDatalog(lines);
	Database db;
	Interpreter i;
	i.Run(&dp, &db);
	return 0;
}	
