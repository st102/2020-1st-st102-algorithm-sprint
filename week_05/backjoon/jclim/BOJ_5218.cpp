#include <iostream>
#include <string>

using namespace std;

int testcases;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> testcases;

	for (int i = 0; i < testcases; i++) {
		string str1, str2;
		cin >> str1 >> str2;

		cout << "Distances: ";

		for (int j = 0; j < str1.length(); j++) {
			if (str1[j] > str2[j]) {
				cout << str2[j] + 26 - str1[j] << " ";
			}
			else {
				cout << str2[j] - str1[j] << " ";
			}		
		}

		cout << "\n";
	}
}