#include <vector>

using namespace std;

int findOdd(const std::vector<int>& numbers){
  int Odd_count=0;
  
  for(auto i : numbers) {
    Odd_count=0;
    for(auto j : numbers) {
      if(i==j) {
        Odd_count++;
      }
    }
    if(Odd_count%2==1) {
      return i;
    }
  }
}