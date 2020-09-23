#include <string>

using namespace std;

std::string to_camel_case(std::string text) {
  string restr;
  int count=0;
  for(int i=0; i<text.length(); i++) {
    if(text[i]=='_' || text[i]=='-') {
      restr+=toupper(text[i+1]);
      i++;
    } else restr+=text[i];
    count++;
  }
  return restr;
}