#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
  int standard=0;
  string copy_in=in;
  int compare=0;
  int com_count;
  int recount=0;
    
  while(in[standard]!='\0') {
  com_count=0;
  compare=0;
    while(copy_in[compare]!='\0') {
      if(tolower(in[standard])==tolower(copy_in[compare])) { 
        com_count++; 
        copy_in.erase(copy_in.begin()+compare);
        compare--;
      }
      compare++;
      }

    if(com_count>=2) { recount++; }
    standard++;
  }

  return recount;
}