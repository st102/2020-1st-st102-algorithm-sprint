#include <iostream>

using namespace std;

string even_or_odd(int number) {
  string check_number_type;

  (number % 2) == 0 ? (check_number_type = "Even") : (check_number_type = "Odd");
  
  return check_number_type;
}