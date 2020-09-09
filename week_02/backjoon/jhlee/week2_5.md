# 백준 11724 <연결 요소의 개수>

## 문제 설명
그래프에 연결되어 있는 집합의 개수를 출력하라.

## 나의 풀이법
```c++

int n, m;
vector<int> edge[1001];
bool check[1001];
int result = 0;

void dfs(int vertex) {
	check[vertex] = true;

	for (int i = 0; i < edge[vertex].size(); i++) {
		if (!check[edge[vertex][i]]) dfs(edge[vertex][i]);
	}
}
** dfs 방식으로 인접리스트가 이어져있다면 이동하여 check=true를 해주었다.


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

cin >> n >> m;
for (int i = 0; i < m; i++) {
	int s, e;
	cin >> s >> e;

	edge[s].push_back(e);
	edge[e].push_back(s);
}
** 인접리스트를 사용하여 입력 받아주었다.


for (int i = 1; i <= n; i++) {
	if (!check[i]) {
		dfs(i);
		result++;
	}
}
cout << result << '\n';
** 모든 정점에 대해서 dfs 방식을 통해 연결되어 있는것이 있다면 안세고 연결되지 않은 상태라면 +1 해준다. 이후 출력



## 다른 방법의 풀이
dfs 대신 bfs 사용

void bfs(int vertex) {
	queue<int> q;
	q.push(vertex);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		check[temp] = true;

		for (int i = 0; i < edge[temp].size(); i++) {
			if (!check[edge[temp][i]]) q.push(edge[temp][i]);
		}
	}
}
** 위 코드에서 dfs 대신 bfs를 사용한 코드이다. 큐를 사용하여 구현하였고 dfs 대신 이 bfs를 사용해도 가능하다.


## 반성할 점


## 배운점
