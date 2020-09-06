#include <iostream>
#include <queue>

using namespace std;

int row, col;
int board[8][8];
int answer;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

void count_safe(int w1, int w2, int w3) {
	if (board[w1 / col][w1 % col] != 0) return;
	if (board[w2 / col][w2 % col] != 0) return;
	if (board[w3 / col][w3 % col] != 0) return;

	int temp_board[8][8];
	copy(&board[0][0], &board[0][0] + 8 * 8, &temp_board[0][0]);

	temp_board[w1 / col][w1 % col] = 1;
	temp_board[w2 / col][w2 % col] = 1;
	temp_board[w3 / col][w3 % col] = 1;

	queue<pair<int, int>> q;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (temp_board[i][j] == 2) q.push({ j, i });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= col || ny >= row) continue;		
			if (temp_board[ny][nx] != 0) continue;

			temp_board[ny][nx] = 2;

			q.push({ nx, ny });
		}
	}

	int cnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (temp_board[i][j] == 0) cnt++;
		}
	}

	answer = max(answer, cnt);
}

int main(int argc, char** argv)
{
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < row * col - 2; i++) {
		for (int j = i + 1; j < row * col - 1; j++) {
			for (int k = j + 1; k < row * col; k++) {
				count_safe(i, j, k);
			}
		}
	}

	cout << answer << endl;
}