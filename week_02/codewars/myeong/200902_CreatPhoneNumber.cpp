#include <string>
using namespace std;
std::string createPhoneNumber(const int arr [10]){
  string fstr;
  string mstr;
  string lstr;
  string restr;
  for(int i=0; i<3; i++) {
    fstr+=to_string(arr[i]);
  }
  for(int i=3; i<6; i++) {
    mstr+=to_string(arr[i]);
  }
  for(int i=6; i<10; i++) {
    lstr+=to_string(arr[i]);
  }
  
  restr="("+fstr+") "+mstr+"-"+lstr;
  return restr;
}