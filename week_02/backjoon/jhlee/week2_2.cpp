#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	int answer[26];
	memset(answer, -1, 26 * sizeof(int));

	for (int i = 0; i < str.size(); i++) {
		int n = (int)str[i] - 97;

		if (answer[n] == -1)
			answer[n] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << answer[i] << ' ';
	cout << '\n';

	system("pause");
	return 0;
}