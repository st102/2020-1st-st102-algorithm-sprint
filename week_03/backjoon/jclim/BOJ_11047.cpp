#include <iostream>
#define MAX 10

using namespace std;

int num, target;
int cost[MAX];
int answer;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num >> target;

	for (int i = 0; i < num; i++) {
		cin >> cost[i];
	}

	for (int i = num - 1; i >= 0; i--) {
		if (target == 0) break;
		
		while (target >= cost[i]) {
			target -= cost[i];
			answer++;
		}
	}

	cout << answer << "\n";
}