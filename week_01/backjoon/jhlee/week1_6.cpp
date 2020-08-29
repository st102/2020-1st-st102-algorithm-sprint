#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int temp = n;

	int i = 2;
	while (temp != 1) {
		if (temp % i == 0) {
			temp /= i;
			cout << i << '\n';
			continue;
		}
		i++;
	}

	return 0;
}