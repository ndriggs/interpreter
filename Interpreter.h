#pragma once
#include "Datalog.h"
#include "Database.h"
#include "Predicate.h"
#include <string>

using namespace std;

class Interpreter {
public :
	void Run(Datalog* &dl, Database* &db);
	Relation* evaluatePredicate(const Predicate p);
};
