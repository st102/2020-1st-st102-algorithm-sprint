#include <iostream>  
#include <vector>
#include <string>

using namespace std;

string likes(const vector<string>& names)
{
	switch (names.size()) {
	case 0: return "no one likes this";
	case 1: return names[0] + " likes this";
	case 2: return names[0] + " and " + names[1] + " likes this";
	case 3: return names[0] + ", " + names[1] + " and " + names[2] + " likes this";
	default: return names[0] + ", " + names[1] + " and " + to_string(names.size() - 2) + " likes this";
	}
}