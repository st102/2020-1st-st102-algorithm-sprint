#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	getline(cin, str);

	int cnt = 1;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') cnt++;
	}

	if (str[0] == ' ') cnt--;
	if (str[str.length() - 1] == ' ') cnt--;

	cout << cnt << "\n";
}