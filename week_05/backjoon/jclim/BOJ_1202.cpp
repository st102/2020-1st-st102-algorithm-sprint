#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 300000

using namespace std;

int gems, bags;
pair<int, int> gem[MAX];
int bag[MAX];
long long answer;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> gems >> bags;

	for (int i = 0; i < gems; i++) {
		cin >> gem[i].first >> gem[i].second;
	}

	for (int i = 0; i < bags; i++) {
		cin >> bag[i];
	}

	sort(gem, gem + gems);
	sort(bag, bag + bags);

	priority_queue<int> pq;

	for (int i = 0, j = 0; i < bags; i++) {
		while (j < gems && gem[j].first <= bag[i]) {
			pq.push(gem[j++].second);
		}

		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	
	cout << answer << "\n";
}