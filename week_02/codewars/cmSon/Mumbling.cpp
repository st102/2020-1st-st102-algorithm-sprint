#include <iostream>
#include <string>

using namespace std;

class Accumul
{
public:
    static string accum(const string &s);
};

string Accumul::accum(const string &s){
  string return_text="";
  
  for(int i = 0; i < s.length(); i++){
    return_text += (s[i] > 'Z') ? toupper(s[i]) : s[i];
    char lower = (s[i] > 'Z') ? s[i] : tolower(s[i]);
    
    for(int j = 0; j < i; j++){
      return_text += lower;
    }
    
    return_text += '-';
  }
  return_text.pop_back();
  
  return return_text;
}