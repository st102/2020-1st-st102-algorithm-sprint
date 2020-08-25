#include <iostream>
#include <string>

using namespace std;



int main() {

	string inputStr;
	int num_of_vowels = 0;

	cin >> inputStr;


	for (int i = 0; i < inputStr.length(); i++) {
		if (inputStr[i] == 'a' || inputStr[i] == 'e' || inputStr[i] == 'i' || inputStr[i] == 'o' || inputStr[i] == 'u')
		{
			num_of_vowels++;
		}
	}

	cout << num_of_vowels;
	
	return 0;
}
 


