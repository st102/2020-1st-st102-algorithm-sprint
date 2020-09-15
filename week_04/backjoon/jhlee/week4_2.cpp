#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int l, p, v;
	int counts = 1;

	cin >> l >> p >> v;

	while (1) {
		if (l == 0 && p == 0 && v == 0)
			break;

		long ans = 0;

		int quotient = v / p;
		int remainder = min(v % p, l);
		ans = l * quotient + remainder;

		cout << "Case " << counts << ": " << ans << '\n';

		cin >> l >> p >> v;
		counts++;
	}

	system("pause");
	return 0;
}