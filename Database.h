#include "Relation.h"
#include <unordered_map>
#include <string>

using namespace std;

class Database {
private:
	unordered_map<string, Relation> relations;
public:
	void addRelation(string name, Relation r);
}
