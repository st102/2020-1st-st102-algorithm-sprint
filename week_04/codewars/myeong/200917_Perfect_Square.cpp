#include <cmath>
long int findNextSquare(long int sq) {
  if(floor(sqrt(sq))==ceil(sqrt(sq)))
    return pow(sqrt(sq)+1,2);
  return -1;
}