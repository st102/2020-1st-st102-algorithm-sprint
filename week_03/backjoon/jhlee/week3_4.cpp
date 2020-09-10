#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000000
#define MAX_NODE 1001

int N, M, X;
int dist[MAX_NODE];
vector<pair<int, int>> v[MAX_NODE];

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int index = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (dist[index] < distance)
			continue;

		for (int i = 0; i < v[index].size(); i++) {
			int nextIndex = v[index][i].first;
			int nextDist = distance + v[index][i].second;

			if (nextDist < dist[nextIndex]) {
				dist[nextIndex] = nextDist;
				pq.push(make_pair(nextIndex, -nextDist));
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> X;
	int keyX[MAX_NODE] = { 0, };

	for (int i = 1; i <= N; i++)
			dist[i] = INF;
	
	for (int i = 0; i < M; i++) {
		int start, end, coast;
		cin >> start >> end >> coast;

		v[start].push_back(make_pair(end, coast));
	}
	int answer = 0;

	dijkstra(X);
	copy(dist, dist + N + 1, keyX);

	for (int i = 1; i <= N; i++) {
		if (X == i)
			continue;
		for (int j = 1; j <= N; j++) 
			dist[j] = INF;

		dijkstra(i);
		answer = max(answer, dist[X] + keyX[i]);
	}

	cout << answer << '\n';
	
	system("pause");
	return 0;
}