#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int a[9][9];
int temp[9][9];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int result = 0;

// BFS 방식으로 0의 개수 세어주는 함수
void count() {
	queue<pair<int,int>> q;
	bool check[9][9] = { false, };
	int co[9][9];
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			co[i][j] = temp[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (co[i][j] == 2) {
				q.push(pair<int, int> (i, j));
				check[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (!check[nx][ny] && co[nx][ny] != 1) {
					check[nx][ny] = true;
					co[nx][ny] = 2;
					q.push(pair<int, int>(nx, ny));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (co[i][j] == 0)
				sum++;
	}
	
	result = max(result, sum);
}

// 하나의 지점을 고르는 함수 3개를 고를때까지 반복
void find(int select, int index) {
	if (index > n * m)
		return;

	if (select == 3) {
		count();
		return;
	}

	if (temp[index / m][index % m] == 0) {
		// 선택o
		temp[index / m][index % m] = 1;
		find(select+1, index + 1);

		// 선택x
		temp[index / m][index % m] = 0;
		find(select, index + 1);
	}
	else
		find(select, index + 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			temp[i][j] = a[i][j];
	}

	find(0, 0);

	cout << result << '\n';

	system("pause");
	return 0;
}