# 백준 14502 <DFS와 BFS>

# 문제 설명
주어지는 입력에 대해서 각각 DFS와 BFS 순으로 출력하는 문제

## 나의 풀이 방법
```c++

* DFS 풀이
void DFS(int node) {
	check[node] = true;

	cout << node << ' ';

	for (int i = 0; i < v[node].size(); i++) {
		if (!check[v[node][i]])
			DFS(v[node][i]);

	}
}
** 매개변수로 현재 지점의 노드를 출력해주고 이 노드와 연결되어 있는 노드에 재귀함수를 통해 접근한다. 이때 이미 갔던 노드라면 가지 않는다.


* BFS 풀이
void BFS() {
	queue<int> q;
	q.push(start);
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (check[x])
			continue;

		check[x] = true;
		cout << x << ' ';

		for (int i = 0; i < v[x].size(); i++) {
			if (!check[v[x][i]])
				q.push(v[x][i]);
		}
	}
}
** queue를 이용하여 현재 자신과 연결되어 있는 노드를 큐에 집어 넣어줌으로써 풀이하였다.


## Action Item
전에 풀어봤던 문제로 비교적 수월하게 해결하였다.
