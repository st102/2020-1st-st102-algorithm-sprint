#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char> s;
		bool check = false;

		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') s.push('(');
			else {
				if (s.size() == 0) {
					cout << "NO" << '\n';
					check = true;
					break;
				}
				s.pop();
			}
		}
		if (!check) {
			if(s.size() == 0) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

	system("pause");
	return 0;
}