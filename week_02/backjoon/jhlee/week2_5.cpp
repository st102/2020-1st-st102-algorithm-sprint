#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> edge[1001];
bool check[1001];
int result = 0;

void dfs(int vertex) {
	check[vertex] = true;

	for (int i = 0; i < edge[vertex].size(); i++) {
		if (!check[edge[vertex][i]]) dfs(edge[vertex][i]);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			dfs(i);
			result++;
		}
	}
	cout << result << '\n';

	system("pause");
	return 0;
}