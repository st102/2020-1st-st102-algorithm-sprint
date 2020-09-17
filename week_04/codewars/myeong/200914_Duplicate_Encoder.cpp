#include <string>
#include <algorithm>
using namespace std;
std::string duplicate_encoder(const std::string& word) {
  string restr = word;
  string restr_last;
  int standard = 0;
  int compare = 0;
  int count = 0;
  int length = word.length();

  for (standard = 0; standard < length; standard++) {
    count = 0;
    for (compare = 0; compare < length; compare++) {
      if (tolower(restr[standard]) == tolower(restr[compare])) {
        count++;
      }
    }
    if (count >= 2) {
      restr_last += ")";
    }
    else restr_last += "(";
  }
  return restr_last;
}