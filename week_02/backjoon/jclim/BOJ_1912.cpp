#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[100001];
int answer = -1001;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		dp[i] = max(num, num + dp[i - 1]);
		answer = max(answer, dp[i]);
	}

	cout << answer << "\n";
}