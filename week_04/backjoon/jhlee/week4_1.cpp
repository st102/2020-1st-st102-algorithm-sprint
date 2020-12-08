#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

string str[101];
string colorStr[101];
int n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool check[101][101];

void bfs(int a, int b, string *s) {
	queue<pair<int, int>> q;
	q.push(make_pair(a,b));
	check[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!check[nx][ny] && s[x][y] == s[nx][ny]) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int normal = 0;
	int disability = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (str[i][j] == 'G')
				colorStr[i] += 'R';
			else
				colorStr[i] += str[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				normal++;
				bfs(i, j, str);
			}
		}
	}

	for (int i = 0; i < n; i++)
		memset(check[i], false, sizeof(bool)*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				disability++;
				bfs(i, j, colorStr);
			}
		}
	}

	cout << normal << ' ' << disability << '\n';

	system("pause");
	return 0;
}