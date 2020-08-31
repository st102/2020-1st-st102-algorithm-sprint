#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string word;
	cin >> word;

	int alphabet[26];
	fill_n(alphabet, 26, -1);

	for (int i = 0; i < word.length(); i++) {
		if (alphabet[word[i] - 'a'] == -1) alphabet[word[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
}