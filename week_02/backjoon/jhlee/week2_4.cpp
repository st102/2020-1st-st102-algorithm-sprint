#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cabbage[50][50];
bool check[50][50];
int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int x, int y) {
	check[x][y] = true;

	for (int q = 0; q < 4; q++) {
		int nx = x + dx[q];
		int ny = y + dy[q];

		if (0 <= nx && nx < m && 0 <= ny && ny < n) {
			if (!check[nx][ny] && cabbage[nx][ny] == 1)
				dfs(nx, ny);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		int k;
		cin >> m >> n >> k;
		int answer = 0;

		for (int i = 0; i < 50; i++) {
			memset(cabbage[i], 0, sizeof(int) * 50);
			memset(check[i], false, sizeof(bool) * 50);
		}
		for (int i = 0; i < k; i++) {
				int x, y;
				cin >> x >> y;

				cabbage[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j] && cabbage[i][j] == 1) {
					dfs(i, j);
					answer++;
				}
			}
		}
		
		cout << answer << '\n';
	}

	system("pause");
	return 0;
}