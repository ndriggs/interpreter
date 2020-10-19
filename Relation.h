#include <set>
#include <string>
#include <attrList>
#include <vector>

using namespace std;

class Relation {
private:
	string name;
	Header header;
	set<Tuple> tuples;

public:
	Relation(string schemeName, vector<string> attrList);
	void addTuple(string relName, vector<string> values);

	Relation select1(Relation r, int index, string value);
	Relation select2(Relation r, int index1, int index2);
	Relation project(Relation r, vector<string> indices);
	Relation rename(Relation r);
}
