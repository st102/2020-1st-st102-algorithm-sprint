#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int list[100001];
	int dp[10001];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> list[i];

	dp[0] = list[0];

	for (int i = 1; i < n; i++) {
		if (dp[i - 1] + list[i] > list[i])
			dp[i] = dp[i - 1] + list[i];
		else
			dp[i] = list[i];
	}

	int result = dp[0];

	for (int i = 1; i < n; i++) result = max(result, dp[i]);

	cout << result << '\n';

	system("pause");
	return 0;
}