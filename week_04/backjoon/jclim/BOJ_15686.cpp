#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 50

using namespace std;

int N, M, dist[MAX * MAX];
int answer = INT_MAX;
vector<pair<int, int>> house, chicken;
vector<int> index;

void calc_dist(int x, int y) {
	for (int i = 0; i < house.size(); i++) {
		dist[i] = min(dist[i], abs(x - house[i].first) + abs(y - house[i].second));
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) {
				house.push_back({ j, i });
			}
			else if (num == 2) {
				chicken.push_back({ j, i });
			}
		}
	}

	for (int i = 0; i < chicken.size() - M; i++) {
		index.push_back(0);
	}

	for (int i = 0; i < M; i++) {
		index.push_back(1);
	}

	do {
		fill(dist, dist + house.size(), INT_MAX);

		for (int i = 0; i < index.size(); i++) {
			if (index[i] == 1) {
				calc_dist(chicken[i].first, chicken[i].second);
			}
		}

		int sum_dist = 0;

		for (int i = 0; i < house.size(); i++) {
			sum_dist += dist[i];
		}

		answer = min(answer, sum_dist);
	} while (next_permutation(index.begin(), index.end()));

	cout << answer << "\n";
}