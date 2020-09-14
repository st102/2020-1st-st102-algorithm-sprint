#include <regex>
#include <string>

using namespace std;

size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
  string copy_in = string(in);
	size_t result = 0;

	for (int i = 0; i < copy_in.length(); i++)
		copy_in[i] = ('A' <= copy_in[i] && copy_in[i] <= 'Z') ? tolower(copy_in[i]) : copy_in[i];


	while(!copy_in.empty()){
		char character = copy_in.front();
		regex regex_word({'[',character,']'});
		if (copy_in.find(character, 1) != string::npos) {
			result++;
		}
		copy_in = regex_replace(copy_in, regex_word, "");
	}
  
  return result;
}