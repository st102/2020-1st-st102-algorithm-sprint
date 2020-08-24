#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a[21];
	int n;
	
	cin >> n;

	a[0] = 0;
	a[1] = 1;
	a[2] = 1;

	for (int i = 3; i <= n; i++)
		a[i] = a[i - 1] + a[i - 2];

	cout << a[n] << '\n';

	system("pause");
	return 0;
}