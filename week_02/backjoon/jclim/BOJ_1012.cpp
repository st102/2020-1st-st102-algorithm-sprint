#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int testcases, col, row, cabbages;
bool board[50][50];
bool visited[50][50];

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void bfs(int x, int y) {
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push({ x , y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= col || ny >= row) continue;
			if (board[ny][nx] == false || visited[ny][nx] == true) continue;

			visited[ny][nx] = true;

			q.push({ nx, ny });
		}
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> testcases;

	for (int i = 0; i < testcases; i++) {
		cin >> col >> row >> cabbages;

		memset(board, false, sizeof(board));
		memset(visited, false, sizeof(visited));

		for (int j = 0; j < cabbages; j++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = true;
		}

		int answer = 0;

		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (board[j][k] == true && visited[j][k] == false) {
					bfs(k, j);
					answer++;
				}
			}
		}

		cout << answer << "\n";
	}
}