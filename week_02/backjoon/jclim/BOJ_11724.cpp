#include <iostream>

using namespace std;

int vertices, edges;
int root[1001];
int ranks[1001];

int find(int x) {
	if (root[x] == x) return x;
	else return root[x] = find(root[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (ranks[x] < ranks[y]) root[x] = y;
	else root[y] = x;
	if (ranks[x] == ranks[y]) ranks[x]++;
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1; i < 1001; i++) {
		root[i] = i;
		ranks[i] = 0;
	}

	cin >> vertices >> edges;

	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		uni(u, v);
	}

	int ans = 0;

	for (int i = 1; i <= vertices; i++) {
		if (root[i] == i) ans++;
	}

	cout << ans << "\n";
}