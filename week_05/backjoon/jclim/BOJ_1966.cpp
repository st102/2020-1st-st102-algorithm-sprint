#include <iostream>
#include <queue>

using namespace std;

int testcases, docs, target;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> testcases;

	for (int i = 0; i < testcases; i++) {
		cin >> docs >> target;

		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int cnt = 0;

		for (int j = 0; j < docs; j++) {
			int num;
			cin >> num;

			q.push({ num, j });
			pq.push(num);
		}

		while (!q.empty()) {
			int priority = q.front().first;
			int index = q.front().second;
			q.pop();

			if (priority == pq.top()) {
				pq.pop();
				cnt++;

				if (index == target) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push({ priority, index });
			}
		}
	}
}