#include <iostream>
#define MAX 301

using namespace std;

int A, B, C, num;
int dp[MAX];

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C >> num;

	dp[A] = dp[B] = dp[C] = 1;

	for (int i = 1; i <= num; i++) {		
		if (i > A && i < B) {
			dp[i] = dp[i - A];
		}
		else if (i > B && i < C) {
			dp[i] = dp[i - A] + dp[i - B];
		}
		else if (i > C) {
			dp[i] = dp[i - A] + dp[i - B] + dp[i - C];
		}
	}

	if (dp[num] != 0) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}