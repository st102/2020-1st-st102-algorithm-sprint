#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int V;
vector<int> arr[1001];
queue<int> q;
bool visited[1001];

void dfs(int index)
{
	visited[index] = true;
	cout << index << " ";
	for (int i = 0; i < arr[index].size(); i++) {
		if (visited[arr[index][i]] == false) {
			dfs(arr[index][i]);
		}
	}
}

void bfs(int index)
{
	q.push(index);
	visited[index] = true;

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		
		cout << num << " ";
		for (int i = 0; i < arr[num].size(); i++) {
			if (visited[arr[num][i]] == false) {
				q.push(arr[num][i]);
				visited[arr[num][i]] = true;
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> V;

	for (int i = 0; i < 1001; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		arr[n1].push_back(n2);
		arr[n2].push_back(n1);
	}

	for (int i = 1; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	dfs(V);

	for (int i = 0; i < 1001; i++) {
		visited[i] = false;
	}
	cout << "\n";

	bfs(V);
}