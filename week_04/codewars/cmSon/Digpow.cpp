#include <string>
#include <cmath>

using namespace std;

class DigPow
{
public:
  static int digPow(int n, int p);
};

int DigPow::digPow(int n, int p){
  string n_to_string = to_string(n);
  int digit_sum = 0;
  
  for(auto digit : n_to_string){
    digit_sum += pow(digit - '0', p++);
  }
  
  return (digit_sum % n == 0) ? digit_sum / n : -1;
}