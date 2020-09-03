#include <iostream>

using namespace std;

int digital_root(int n)
{
    int check_digit = n  / 10;
  
    if( check_digit == 0){
      return n;
    }else{
      int sum = 0;
      
      while (n != 0){
        sum += n % 10;
        n /= 10;
      }
           
      return digital_root(sum);
    }
  
}