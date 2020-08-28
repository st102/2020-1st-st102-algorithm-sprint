#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
int list[2001];
int m;
int dp[2001][2001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> list[i];
	cin >> m;

	for (int i = 1; i <= n; i++) dp[i][i] = 1;

	for (int i = 1; i < n; i++) {
		if (list[i] == list[i + 1])
			dp[i][i + 1] = 1;
		else
			dp[i][i + 1] = 0;
	}

	for (int i = 2; i < n; i++) {
		for (int j = 1; i + j <= n; j++) {
			if (list[j] == list[i + j] && dp[j + 1][i + j - 1] == 1)
				dp[j][i + j] = 1;
			else
				dp[j][i + j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;

		cout << dp[start][end] << '\n';
	}

	system("pause");
	return 0;
}