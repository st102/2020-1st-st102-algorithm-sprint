#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 26

using namespace std;

int map_size, cnt;
char map[MAX][MAX];
vector<int> answer;

bool is_valid(int x, int y) {
	if (x < 1 || y < 1 || x > map_size || y > map_size) {
		return false;
	}
	else if (map[y][x] != '1') {
		return false;
	}
	else {
		return true;
	}
}

void dfs(int x, int y)
{
	if (!is_valid(x, y)) return;

	map[y][x] = '2';

	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);

	cnt++;
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> map_size;

	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			if (map[i][j] == '1') {
				cnt = 0;
				dfs(j, i);
				answer.push_back(cnt);			
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}