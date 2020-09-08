#include <iostream>

using namespace std;

int n;
int weight[50];
int height[50];

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> height[i];
	}

	for (int i = 0; i < n; i++) {
		int rank = 1;

		for (int j = 0; j < n; j++) {
			if (weight[i] < weight[j] && height[i] < height[j]) rank++;
		}

		cout << rank << " ";
	}
}