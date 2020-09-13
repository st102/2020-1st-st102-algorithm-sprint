#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {
		string str, answer;
		cin >> str;

		stack<char> s;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') {
				s.push('(');
			}
			else if (s.size() == 0) {
				answer = "NO";
				break;
			}
			else {
				s.pop();
			}
		}

		if (answer == "NO" || s.size() > 0) {
			cout << "NO" << "\n";
		}
		else {
			cout << "YES" << "\n";
		}
	}
}