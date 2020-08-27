#include <iostream>

using namespace std;

void self(bool* arr, int index)
{
	if (arr[index] == false) return;

	int sum = index;
	while (index) {
		sum += index % 10;
		index = index / 10;
	}

	if (sum > 10000) return;

	self(arr, sum);
	arr[sum] = false;
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool arr[10001];
	fill_n(arr, 10001, true);

	for (int i = 1; i <= 10000; i++) {
		self(arr, i);
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i]) cout << i << "\n";
	}
}