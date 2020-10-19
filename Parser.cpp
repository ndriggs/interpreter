#include "Parser.h"
#include "DatalogProgram.h"
#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"
#include <string>
#include <queue>
#include <iostream>

void Parser::check(string tokenName, string line){
	size_t comma_pos;
	comma_pos = line.find(",");
	if(line.substr(1, comma_pos - 1) == tokenName)
		return;
	else
		throw("  " + line);	
}

string Parser::returnTokenType(string line){
	size_t comma_pos;
	comma_pos = line.find(",");
	return line.substr(1, comma_pos - 1);
}

string Parser::getTokenValue(string line){
	size_t first_quote, second_quote;
	first_quote = line.find("\"");
	second_quote = line.find("\"", first_quote + 1);
	return line.substr(first_quote + 1, second_quote - first_quote - 1);
}

DatalogProgram Parser::ParseDatalog(queue<string> &input){
	try{
		check("SCHEMES", input.front());
		input.pop();
		check("COLON", input.front());
		input.pop();
		ParseScheme(input);
		ParseSchemeList(input);
		check("FACTS", input.front());
	       	input.pop();	
		check("COLON", input.front());
		input.pop();
		ParseFactList(input);
		check("RULES", input.front());
		input.pop();
		check("COLON", input.front());
		input.pop();
		ParseRuleList(input);
		check("QUERIES", input.front());
		input.pop();
		check("COLON", input.front());
		input.pop();
		ParseQuery(input);
		ParseQueryList(input);
		check("EOF", input.front());
		cout << "Success!" << endl;
		cout << dp.toString() << endl;
	} catch(string line) {
		cout << "Failure!" << endl << line << endl;
	}
	return dp;
}



void Parser::ParseSchemeList(queue<string> &input){
	string tokenType = returnTokenType(input.front());
	if(tokenType != "ID")
		return;
	ParseScheme(input);
	ParseSchemeList(input);
}

void Parser::ParseFactList(queue<string> &input){
	string tokenType = returnTokenType(input.front());
	if(tokenType != "ID")
	       return;
	ParseFact(input);
	ParseFactList(input);
}

void Parser::ParseRuleList(queue<string> &input){
	string tokenType = returnTokenType(input.front());
	if(tokenType != "ID")
		return;
	ParseRule(input);
	ParseRuleList(input);
}

void Parser::ParseQueryList(queue<string> &input){
	if(returnTokenType(input.front()) != "ID")
		return;
	ParseQuery(input);
	ParseQueryList(input);
}

void Parser::ParseScheme(queue<string> &input){
	check("ID", input.front());
	string id = getTokenValue(input.front());
	Predicate* s = new Predicate(id);
    	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	check("ID", input.front());
	id = getTokenValue(input.front());
	vector<string> ids;
	ids.push_back(id);
	input.pop();
	ParseIdList(input, ids);
	for(int i = 0; (unsigned)i < ids.size(); i++){
		s->addParameter(new Parameter(ids[i]));
	}
	check("RIGHT_PAREN", input.front());
	input.pop();
	dp.addScheme(s);
	return;	
}

void Parser::ParseFact(queue<string> &input){
	check("ID", input.front());
	string id = getTokenValue(input.front());
	Predicate* f = new Predicate(id);
	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	check("STRING", input.front());
	string str = getTokenValue(input.front());
	dp.insertDomainString(str);
        f->addParameter(new Parameter(str));	
	input.pop();
	ParseStringList(input, f);
	check("RIGHT_PAREN", input.front());
	input.pop();
	check("PERIOD", input.front());
	input.pop();
	dp.addFact(f);
	return;
}

void Parser::ParseRule(queue<string> &input){
	Predicate* hp = new Predicate();
	ParseHeadPredicate(input, hp);
	Rule* r = new Rule(hp);
	check("COLON_DASH", input.front());
	input.pop();
	Predicate* p = new Predicate();
	ParsePredicate(input, p);
	vector<Predicate*> preds;
	preds.push_back(p);
	ParsePredicateList(input, preds);
	check("PERIOD", input.front());
	input.pop();
	for(int i = 0; (unsigned)i < preds.size(); i++){
		r->addPredicate(preds[i]);
	}
	dp.addRule(r);
	return;
}

void Parser::ParseQuery(queue<string> &input){
	if(returnTokenType(input.front()) != "ID")
		return;
	Predicate* q = new Predicate("fake id");
	ParsePredicate(input, q);
	check("Q_MARK", input.front());
 	input.pop();
	dp.addQuery(q);  
	return;
}

void Parser::ParseHeadPredicate(queue<string> &input, Predicate*& p){
	check("ID", input.front());
	string id = getTokenValue(input.front());
	p->addId(id);
	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	check("ID", input.front());
	id = getTokenValue(input.front());
	input.pop();
	vector<string> ids;
	ids.push_back(id);
	ParseIdList(input, ids); 
	check("RIGHT_PAREN", input.front());
	input.pop();
	for(int i = 0; (unsigned)i < ids.size(); i++){
		p->addParameter(new Parameter(ids[i]));
	}
	return;
}

void Parser::ParsePredicate(queue<string> &input, Predicate*& p){
	check("ID", input.front());
	string id = getTokenValue(input.front());
	p->addId(id);
	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	Parameter* param = new Parameter();
	ParseParameter(input, param);
	vector<Parameter*> params;
	params.push_back(param);
	ParseParameterList(input, params);
	check("RIGHT_PAREN", input.front());
	input.pop();
	for(int i = 0; (unsigned)i < params.size(); i++){
		p->addParameter(params[i]);
	}
	return;
}

void Parser::ParsePredicateList(queue<string> &input, vector<Predicate*> &preds){
	if(returnTokenType(input.front()) != "COMMA")
		return;
	input.pop();
	Predicate* pred = new Predicate();
	ParsePredicate(input, pred);
	preds.push_back(pred);
	ParsePredicateList(input, preds);
	return;
}

void Parser::ParseParameterList(queue<string> &input, vector<Parameter*> &params){
	if(returnTokenType(input.front()) != "COMMA")
		return;
	input.pop();
	Parameter* param = new Parameter();
	ParseParameter(input, param);
	params.push_back(param);
	ParseParameterList(input, params);
	return;
}

void Parser::ParseStringList(queue<string> &input, Predicate*& f){
	if(returnTokenType(input.front()) != "COMMA")
		return;
	input.pop();
	check("STRING", input.front());
	string str = getTokenValue(input.front());
	dp.insertDomainString(str);
	f->addParameter(new Parameter(str));
	input.pop();
	ParseStringList(input, f);
	return;
}

void Parser::ParseIdList(queue<string> &input, vector<string> &ids){
	string tokenType = returnTokenType(input.front());
	if(tokenType != "COMMA")
		return;
	input.pop();
	check("ID", input.front());
	string id = getTokenValue(input.front());
	ids.push_back(id);
	input.pop();
	ParseIdList(input, ids);
	return;
}
	
void Parser::ParseParameter(queue<string> &input, Parameter*& p){
	string tokenType = returnTokenType(input.front());
	if((tokenType == "STRING") || (tokenType == "ID")){
		string parm = getTokenValue(input.front());
		p->addSome(parm);
		input.pop();
		return;
	} else{
		ParseExpression(input, p);
		return;
	}
}

void Parser::ParseExpression(queue<string> &input, Parameter*& p){
	check("LEFT_PAREN", input.front());
	p->addSome("(");
	input.pop();
	ParseParameter(input, p);
	ParseOperator(input, p);
	ParseParameter(input, p);
	check("RIGHT_PAREN", input.front());
	p->addSome(")");
	input.pop();
	return;
}

void Parser::ParseOperator(queue<string> &input, Parameter*& p){
	string tokenType = returnTokenType(input.front());
	if((tokenType == "ADD") || (tokenType == "MULTIPLY")){
		string op = getTokenValue(input.front());
		p->addSome(op);
		input.pop();
		return;
	}
	else{
		throw(input.front());
	}
}
