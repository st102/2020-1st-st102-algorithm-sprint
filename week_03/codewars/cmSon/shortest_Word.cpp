#include<iostream>
#include<sstream>

using namespace std;

int find_short(string str)
{
  int short_word_length = str.length();
  stringstream ss(str);
  string word;
  
  while(ss >> word)
    short_word_length = ( short_word_length < word.length() )? short_word_length : word.length();
  
  return short_word_length;
}