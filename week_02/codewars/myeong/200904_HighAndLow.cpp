#include <string>
#include <sstream>

using namespace std;
std::string highAndLow(const std::string& numbers){
  istringstream ss(numbers);
  string stringBuffer;
  int i = 0;
  int j = 0;
  int arr[10000];
  int min;
  int max;
  while (getline(ss, stringBuffer, ' ')) {
    arr[j] = atoi(stringBuffer.c_str());
    j++;
  }
  min = arr[0];
  max = arr[0];
  for (i=0; i < j; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  string restr=to_string(max)+" "+to_string(min);
  return restr;
}