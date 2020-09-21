#include<cmath>

long int findNextSquare(long int sq) {
  double root = sqrt(sq);
  
  if(root - (int)root == 0)
    return (root + 1)*(root + 1);
  else
    return -1;
}