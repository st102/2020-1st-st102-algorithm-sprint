#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100

using namespace std;

int num;
char grid[MAX][MAX];
bool visited[MAX][MAX];

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

			if (nx < 0 || ny < 0 || nx >= num || ny >= num) continue;
			if (grid[ny][nx] != grid[cy][cx] || visited[ny][nx] == true) continue;

			visited[ny][nx] = true;

			q.push({ nx, ny });
		}
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> grid[i][j];
		}
	}

	int answer = 0;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (visited[i][j] == false) {
				bfs(j, i);
				answer++;
			}
		}
	}

	cout << answer << " ";

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (grid[i][j] == 'G') grid[i][j] = 'R';
		}
	}

	answer = 0;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (visited[i][j] == false) {
				bfs(j, i);
				answer++;
			}
		}
	}

	cout << answer << "\n";
}