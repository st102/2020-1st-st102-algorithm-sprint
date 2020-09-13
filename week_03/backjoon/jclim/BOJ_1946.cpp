#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> ranks[100000];

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {
		int num;
		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> ranks[j].first >> ranks[j].second;
		}

		sort(ranks, ranks + num);

		int answer = 1;
		int min_rank = ranks[0].second;

		for (int j = 1; j < num; j++) {
			if (ranks[j].second < min_rank) {
				min_rank = ranks[j].second;
				answer++;
			}
		}

		cout << answer << "\n";
	}
}