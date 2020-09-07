#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string highAndLow(const string& numbers){
  char * char_numbers = (char *)numbers.c_str();
  char * number = strtok(char_numbers," ");
  int highest = atoi(number);
  int lowest = atoi(number);
  
  while(number != NULL){
    int number_to_integer = atoi(number);
    
    highest = (highest < number_to_integer)? number_to_integer : highest;
    lowest = (lowest > number_to_integer)? number_to_integer : lowest;
    
    number = strtok(NULL, " ");
  }
  
  return to_string(highest) + " " + to_string(lowest);
}