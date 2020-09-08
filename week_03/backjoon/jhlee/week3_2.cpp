#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_LEN 100

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int x, y;
	bool check[MAX_LEN][MAX_LEN];
	int answer = 0;

	for (int i = 0; i < MAX_LEN; i++)
		memset(check[i], false, sizeof(bool) * MAX_LEN);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		for (int s = x; s < x + 10; s++) {
			for(int t = y; t < y + 10; t++)
				if(!check[s][t]) check[s][t] = true;
		}
	}

	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_LEN; j++)
			if (check[i][j]) answer++;
	}

	cout << answer << '\n';
	
	system("pause");
	return 0;
}