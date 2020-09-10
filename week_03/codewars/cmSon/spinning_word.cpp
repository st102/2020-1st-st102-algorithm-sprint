#include<sstream>
#include<algorithm>

using namespace std;

string spinWords(const string &str)
{
    stringstream ss(str);
    string word;
    string result_sentence = "";

    while (ss >> word) {
        if (word.length() > 4) {
            reverse(word.begin(), word.end());
        }
        result_sentence += word + " ";
    }
    result_sentence.pop_back();
  
  return result_sentence;
}