#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int money[10];
	int n, k;
	int index;
	int answer = 100000001;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> money[i];
		if (money[i] <= k) index = i;
	}

	for (int i = index; i >= 0; i--) {
		int temp = 0;
		int goal = k;
		for (int j = i; j >= 0; j--) {
			int x = goal / money[j];
			temp += x;
			goal -= money[j] * x;

			if (goal == 0)
				break;
		}
		if (goal == 0)
			answer = min(answer, temp);
	}

	cout << answer << '\n';

	system("pause");
	return 0;
}