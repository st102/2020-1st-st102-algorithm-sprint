#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int testcases, num;
int wood[MAX];

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> testcases;

	for (int i = 0; i < testcases; i++) {		
		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> wood[j];
		}

		sort(wood, wood + num);

		int answer = 0;

		for (int j = 2; j < num; j++) {
			answer = max(answer, wood[j] - wood[j - 2]);
		}

		cout << answer << "\n";
	}
}