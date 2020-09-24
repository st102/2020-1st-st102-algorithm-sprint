#include <iostream>
#define MAX 100001

using namespace std;

int gates, planes, answer;
int root[MAX];

int find(int x) {
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	root[x] = y;
}


int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> gates >> planes;

	for (int i = 1; i <= gates; i++) {
		root[i] = i;
	}

	for (int i = 0; i < planes; i++) {
		int num;
		cin >> num;

		int parent = find(num);

		if (parent == 0) {
			break;
		}
		else {
			uni(parent, parent - 1);
			answer++;
		}
	}

	cout << answer << "\n";
}