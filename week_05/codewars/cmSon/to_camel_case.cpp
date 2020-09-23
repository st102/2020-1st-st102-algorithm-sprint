#include <string>

using namespace std;

string to_camel_case(string text) {
  
  string result = "";
  
  for(int i = 0; i < text.length(); i++){
    if(text[i] == '-' || text[i] == '_'){
      result += toupper(text[++i]);
    }else{
      result += text[i];
    }        
  }  
  
  return result;
}