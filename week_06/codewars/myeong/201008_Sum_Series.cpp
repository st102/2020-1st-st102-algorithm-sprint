#include <string>
#include <math.h>
using namespace std;
std::string seriesSum(int n)
{
  double allsum = 0;
  string restr;
  int remember=0;
  for (int under = 0; under <= n - 1; under++) {
    allsum += 1.00 / (1 + (under * 3));
  }
  allsum=round(allsum*100)/100;
  restr = to_string(allsum);
  for (int index = 0; index <= restr.length(); index++) {
    if (restr[index] == '.')
      remember = index;
  }
  return restr.substr(0,remember+3);
}