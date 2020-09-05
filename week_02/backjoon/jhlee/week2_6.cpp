#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 50

int n;
vector<pair<int, int>> info;
int result[MAX_SIZE];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int weight, height;
		cin >> weight >> height;

		info.push_back(pair<int, int>(weight, height));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (info[i].first < info[j].first && info[i].second < info[j].second)
				result[i]++;
		}
	}

	for (int i = 0; i < n; i++) cout << result[i] + 1 << ' ';
	cout << '\n';

	return 0;
}