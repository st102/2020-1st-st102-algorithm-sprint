#include <iostream>
#include <string>

using namespace std;

int main()
{
   string sentence;
   int i = 0;
   int count = 0;

   getline(cin, sentence);
   cout << sentence << endl;

   while (sentence[i]!='\0')
   {
      if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u')
      {
         count++;
      }
      i++;
   }

   cout << "모음의 개수는 : " << count;
   
   return 0;
}