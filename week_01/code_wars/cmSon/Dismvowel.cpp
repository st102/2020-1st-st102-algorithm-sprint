#include <iostream>
#include <string>

using namespace std;

string disemvowel(std::string str)
{
    string result_str = "";
 
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            break;
        default:
            result_str.push_back(str[i]);
            break;
        }
    }

    return result_str;
}