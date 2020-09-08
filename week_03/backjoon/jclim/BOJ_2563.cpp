#include <iostream>
#define MAX 100

using namespace std;

int papers;
bool board[MAX][MAX];
int cnt;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> papers;

	for (int i = 0; i < papers; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = 0; j < 10; j++) {
			fill(board[y + j] + x, board[y + j] + x + 10, true);
		}
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (board[i][j] == true) cnt++;
		}
	}

	cout << cnt << "\n";
}