#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define MAX_LEN 25

int n;
string map[MAX_LEN];
int result[MAX_LEN*MAX_LEN];
bool check[MAX_LEN][MAX_LEN];
int answer = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool checkSize(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < n)
		return true;
	else
		return false;
}

void dfs(int x, int y) {
	check[x][y] = true;
	result[answer]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (checkSize(nx, ny)) {
			if (!check[nx][ny] && map[nx][ny] == '1') dfs(nx, ny);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> map[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && !check[i][j]) {
				dfs(i, j);
				answer++;
			}
		}
	}

	sort(result, result + answer);

	cout << answer << '\n';
	for (int i = 0; i < answer; i++) cout << result[i] << '\n';

	system("pause");
	return 0;
}