#include<vector>

#define N 1
#define S -1
#define W 2
#define E -2

bool isValidWalk(std::vector<char> walk) {
  int return_home = 0;
  
  if(walk.size() != 10) return false;
    
  for (auto direction : walk) {
    return_home += (direction == 'n') ? N : 
                   (direction == 's')? S : 
                   (direction == 'w')? W : E;
  }
  
  return (return_home == 0);
}