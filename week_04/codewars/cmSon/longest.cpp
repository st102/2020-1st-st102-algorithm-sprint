#include <set>

using namespace std;

class TwoToOne
{
public:
    static string longest(const string &s1, const string &s2);
};

string TwoToOne::longest(const string& s1, const string& s2) {
    set<char> strings;
    string result = "";

    for (auto character : s1)  strings.insert(character);

    for (auto character : s2)  strings.insert(character);

    for (auto character : strings)  result += character;

    return result;
}