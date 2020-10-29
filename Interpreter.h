#pragma once
#include "DatalogProgram.h"
#include "Database.h"
#include "Predicate.h"
#include <string>

using namespace std;

class Interpreter {
public :
	void Run(DatalogProgram* dp, Database* &db);
	Relation* evaluatePredicate(Predicate* p);
};
