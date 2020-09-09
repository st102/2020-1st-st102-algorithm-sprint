#include <sstream>
using namespace std;
int find_short(std::string str)
{
  string shortBuffer;
  stringstream ss(str);
  int reshortest = str.length();
  while (getline(ss, shortBuffer, ' ')) {
    if (reshortest > shortBuffer.length()) {
      reshortest = shortBuffer.length();
    }
  }
  
  return reshortest;
}