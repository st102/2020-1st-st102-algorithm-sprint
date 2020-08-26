#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, start;
vector<vector<int>> v;
bool check[1001];

void DFS(int node) {
	check[node] = true;

	cout << node << ' ';

	for (int i = 0; i < v[node].size(); i++) {
		if (!check[v[node][i]])
			DFS(v[node][i]);

	}
}

void BFS() {
	queue<int> q;
	q.push(start);
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (check[x])
			continue;

		check[x] = true;
		cout << x << ' ';

		for (int i = 0; i < v[x].size(); i++) {
			if (!check[v[x][i]])
				q.push(v[x][i]);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> start;
	v.assign(n + 1, vector<int>());

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		v[s].push_back(e);
		v[e].push_back(s);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	DFS(start);
	cout << '\n';

	for (int i = 0; i <= n; i++)
		check[i] = false;

	BFS();
	cout << '\n';

	system("pause");
	return 0;
}