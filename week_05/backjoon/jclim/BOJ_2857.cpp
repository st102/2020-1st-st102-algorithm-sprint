#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> answer;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 5; i++) {
		string str;
		cin >> str;

		if (str.find("FBI") != string::npos) {
			answer.push_back(i);
		}
	}

	if (answer.empty()) cout << "HE GOT AWAY!" << "\n";

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}