#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> salesman;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testcase;
	cin >> testcase;

	while (testcase != 0) {
		int n;
		cin >> n;

		int loser = 0;
		for (int i = 0; i < n; i++) {
			int rank1, rank2;
			cin >> rank1 >> rank2;

			salesman.push_back(make_pair(rank1, rank2));
		}
		sort(salesman.begin(), salesman.end());

		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (salesman[i].second > salesman[j].second) {
					loser++;
					break;
				}
			}
		}
		cout << n - loser << '\n';

		salesman.clear();
		testcase--;
	}

	system("pause");
	return 0;
}