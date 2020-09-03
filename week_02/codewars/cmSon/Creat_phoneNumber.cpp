#include <iostream>
#include <string>

using namespace std;

string createPhoneNumber(const int arr [10]){
  char phoneNumber[15];
  char *phoneNumber_format = "(%d%d%d) %d%d%d-%d%d%d%d";
  
  sprintf(phoneNumber,phoneNumber_format, 
          arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);

  return phoneNumber;
}