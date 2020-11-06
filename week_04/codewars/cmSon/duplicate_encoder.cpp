#include <string>
#include <map>

using namespace std;

string duplicate_encoder(const string& word){
  map<char,int> character_count;
  string result = "";
  
  for(auto character : word)
    character_count[tolower(character)]++;
  
  for(auto character : word)
    result += (character_count[tolower(character)] > 1)? ")" : "(";
  
  
  return result;
}