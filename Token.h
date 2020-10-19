#pragma once
#include <string>


using namespace std;

enum TokenType{COMMA,PERIOD,Q_MARK,LEFT_PAREN,RIGHT_PAREN,COLON,COLON_DASH,MULTIPLY,ADD,SCHEMES,FACTS,RULES,QUERIES,ID,STRING,COMMENT,UNDEFINED,END_OF_FILE};

class Token {
	private:
		TokenType type;
		string value;
		int line;
	public:
		Token(TokenType type, string input, int line);
		string out();	
		TokenType getTokenType();
		//maybe a output token function
};
