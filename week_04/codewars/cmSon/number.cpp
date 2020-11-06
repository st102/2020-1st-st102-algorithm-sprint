#include <utility>
#include <vector>

using namespace std;

unsigned int number(const vector<pair<int, int>>& busStops){
  int last_people = 0;
  
  for(auto info : busStops)
    last_people += (info.first - info.second);
  
  return last_people;
}