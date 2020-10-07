#include <utility>
#include <vector>

using namespace std;
unsigned int number(const std::vector<std::pair<int, int>>& busStops){
  int people=0;
  int busstops=0;
  
  for(int i=0; i<busStops.size(); i++) {
    busstops+=busStops[i].first;
    people+=busStops[i].second;
  }
  if(busstops-people>0) {
    return busstops-people;
  } else return 0;
}