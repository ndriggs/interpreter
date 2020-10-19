#include "Lexer.h"
#include <iostream>

using namespace std;

Lexer::Lexer(){
	machines.push_back(new MatcherAutomaton(",", COMMA));
	machines.push_back(new MatcherAutomaton(".", PERIOD));
	machines.push_back(new MatcherAutomaton("?", Q_MARK));
	machines.push_back(new MatcherAutomaton("(", LEFT_PAREN));
	machines.push_back(new MatcherAutomaton(")", RIGHT_PAREN));
	machines.push_back(new MatcherAutomaton(":", COLON));
	machines.push_back(new MatcherAutomaton(":-", COLON_DASH));
	machines.push_back(new MatcherAutomaton("*", MULTIPLY));
	machines.push_back(new MatcherAutomaton("+", ADD));
	machines.push_back(new MatcherAutomaton("Schemes", SCHEMES));
	machines.push_back(new MatcherAutomaton("Facts", FACTS));
	machines.push_back(new MatcherAutomaton("Rules", RULES));
	machines.push_back(new MatcherAutomaton("Queries", QUERIES));
	machines.push_back(new Identity());
	machines.push_back(new String());
	machines.push_back(new Comment());
	machines.push_back(new NotAString());
	machines.push_back(new NoEndComment());
	machines.push_back(new EndOfFile());
}

void Lexer::addToken(Token tolkien){
	tokens.push_back(tolkien);
}

string Lexer::print(){
	stringstream str;
	for(int i = 0; (unsigned)i < tokens.size(); i++){                          
		if(tokens[i].getTokenType() != COMMENT)
			str << tokens[i].out() << endl;		
	}
	str << "Total Tokens = " << tokens.size();
	return str.str();	
}

void Lexer::Run(string input){
	int lineNumber = 1;
	int maxNewLines = 0;
	while(input.size() > 0){
		while((input[0] == '\n') || (input[0] == '\t') || (input[0] == ' ')){ 
			if(input[0] == '\n') 
				lineNumber += 1;
			input.erase(0,1);
		}
		int maxRead = 0;
		Automaton* maxMachine = machines[0];
		for(int i = 0; (unsigned)i < machines.size(); i++){
			int inputRead = machines[i]->Read(input);
			if(inputRead > maxRead) {
				maxRead = inputRead;
				maxMachine = machines[i];
				maxNewLines = machines[i]->NewLinesRead();
			}
		}
		if(maxRead > 0){
			Token* newToken = maxMachine->CreateToken(input.substr(0, maxRead), lineNumber);
			lineNumber += maxNewLines;
			tokens.push_back(*newToken);
		} else {
			maxRead = 1;
			Token undefToken(UNDEFINED, input.substr(0, maxRead), lineNumber);
			tokens.push_back(undefToken);	
		}
		input.erase(0, maxRead);
	}
	tokens.pop_back();
	Token end_token(END_OF_FILE, "", lineNumber);
	tokens.push_back(end_token);
	
}
