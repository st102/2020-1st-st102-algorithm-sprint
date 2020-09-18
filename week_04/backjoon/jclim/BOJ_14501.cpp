#include <iostream>
#include <algorithm>
#define MAX 17

using namespace std;

int days, answer;
pair<int, int> counsel[MAX];
int dp[MAX];

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> days;

	for (int i = 1; i <= days; i++) {		
		cin >> counsel[i].first >> counsel[i].second;
	}

	for (int i = 1; i <= days; i++) {
		if (i + counsel[i].first <= days + 1) {
			dp[i + counsel[i].first] = max(dp[i + counsel[i].first], dp[i] + counsel[i].second);
			answer = max(answer, dp[i + counsel[i].first]);
		}

		dp[i + 1] = max(dp[i + 1], dp[i]);
		answer = max(answer, dp[i + 1]);
	}

	cout << answer << "\n";
}