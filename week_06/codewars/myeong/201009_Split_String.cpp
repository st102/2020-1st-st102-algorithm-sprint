#include <string>
#include <vector>
using namespace std;
std::vector<std::string> solution(const std::string &s)
{
  vector<string> revec;
  string restr;
  int length=s.length();
  int two_count=1;
  for(int index=0; index<length; index++) {
    restr+=s[index];
    if(two_count==2) {
      revec.push_back(restr);
      two_count=0;
      restr="";
    }
    two_count++;
  }
  if(length%2==1) {
    restr=s[length-1];
    revec.push_back(restr+"_");
  }
    return revec;
}