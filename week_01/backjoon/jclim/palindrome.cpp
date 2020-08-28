#include <iostream>

using namespace std;

int num;
int arr[2001];
int questions;
bool dp[2001][2001];

int palindrome(int s, int e) {
	int cnt = 0;

	for (int i = 0; i < (e - s + 1) / 2; i++) {
		if (dp[s + i][e - i]) break;
		if (arr[s + i] != arr[e - i]) return 0;
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		dp[s + i][e - i] = true;
	}

	return 1;
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
	}

	cin >> questions;

	for (int i = 0; i < questions; i++) {
		int s, e;
		cin >> s >> e;
		cout << palindrome(s, e) << "\n";
	}
}