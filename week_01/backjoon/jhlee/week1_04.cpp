#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	bool check[10001] = {
		false,
	};

	for (int i = 1; i <= 10000; i++) {
		int sum = i;
		int x = i;

		while (x != 0) {
			sum += (x % 10);
			x /= 10;
		}
		if (sum > 10000) continue;

		check[sum] = true;
	}

	for (int i = 1; i <= 10000; i++) {
		if (!check[i]) cout << i << '\n';
	}

	system("pause");
	return 0;
}