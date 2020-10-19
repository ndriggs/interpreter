#include "Tuple.h"
#include <string>
#include <vector>

using namespace std;

Tuple::Tuple(vector<string> values){
	this->values = values;
}

bool Tuple::operator< (const Tuple & other) const {

}
