#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 1001

using namespace std;

int students, roads, target, answer;
vector<pair<int, int>> adj[MAX], rev_adj[MAX];
int dist[MAX], rev_dist[MAX];

void dijkstra(int* dist, vector<pair<int, int>>* adj) {
	fill(dist, dist + MAX, INT_MAX);
	dist[target] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, target });

	while (!pq.empty()) {
		int from = pq.top().second;

		pq.pop();

		for (int i = 0; i < adj[from].size(); i++) {
			int to = adj[from][i].first;
			int cost = adj[from][i].second;

			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				pq.push({ -dist[to], to });
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> students >> roads >> target;

	for (int i = 0; i < roads; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;

		adj[from].push_back({ to, weight });
		rev_adj[to].push_back({ from, weight });
	}
	
	dijkstra(dist, adj);
	dijkstra(rev_dist, rev_adj);

	for (int i = 1; i <= students; i++) {
		answer = max(answer, dist[i] + rev_dist[i]);
	}
	cout << answer << "\n";
}