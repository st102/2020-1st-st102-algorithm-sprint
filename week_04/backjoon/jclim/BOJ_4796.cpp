#include <iostream>
#include <algorithm>

using namespace std;

int L, P, V;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt = 1;

	while (true) {
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) break;

		cout << "Case " << cnt++ << ": " << (V / P) * L + min(V % P, L) << "\n";
	}
}