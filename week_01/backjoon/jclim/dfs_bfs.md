# DFS와 BFS

## 문제 설명

* 그래프를 DFS와 BFS로 탐색해 각각 방문한 점을 순서대로 출력하는 문제

## 나의 풀이 방법

```c++
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
```

> 재귀 호출을 사용해 연결된 정점들을 방문한다. `visited` 배열을 사용해 아직 방문하지 않은 정점들을 방문하도록 했다.  

```c++
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
```

> 큐를 사용해 연결된 정점들을 방문한다. DFS와 마찬가지로 `visited` 배열을 사용해 아직 방문하지 않은 정점들을 방문하도록 했다.  

```c++
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
```

> 값을 입력받아 인접 리스트 방식으로 저장하고 정점 번호가 작은 것을 먼저 방문하기 위해 정렬을 했다. 그리고 dfs와 bfs 함수를 호출해 답을 출력했다.

## 다른 사람의 풀이 방법

```c++
#include <iostream>
#include <queue>
#include <cstring>        // memset

using namespace std;

int v, e, startNum;
int arr[1001][1001];     // 인접행렬
bool check[1001];        // check배열
void dfs(int x);
void bfs(int x);

int main()
{
    /*정점의 개수, 간선의 개수, 탐색시작 정점의 번호 입력받기*/
    cin >> v >> e >> startNum;

    /*입력을 받아 인접행렬 만들기*/
    while(e--){
        int x, y;
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1; // 주어진 간선이 양방향이라고 하였으므로
    }

    /*인접행렬을 이용해서 DFS, BFS탐색하기*/
    dfs(startNum);
    cout << "\n";
    
    memset(check, false, sizeof(check));

    bfs(startNum);
    cout << "\n";
}

void dfs(int x){
    cout << x << " ";
    check[x] = true;

    for (int i = 1; i <= v; i++){
        if (check[i] == false && arr[x][i] == 1)
            dfs(i);
    }
}

void bfs(int x){
    queue<int> q;

    q.push(x);
    check[x] = true;

    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for(int i = 1; i <= v; i++){
            if(check[i] == false && arr[currentNode][i] == 1){
                q.push(i);
                check[i] = true;
            }
        }
    }
}
```

> 이 풀이에서는 인접 리스트가 아닌 인접 행렬을 사용하여 그래프를 나타낸다.  
> 인접 리스트는 전체 노드 탐색 시 시간복잡도 O(E)이고 인전 행렬은 전체 노드 탐색 시 시간복잡도 O(V^2)이다.  
> 간선(E)과 정점(V)의 수를 확인하여 상황에 맞게 쓰는 것이 좋을 것 같다.  

## 배운점
> DFS와 BFS를 사용하여 그래프를 탐색하는 방법을 공부할 수 있었다.  
> 그래프를 나타내는 두가지 방식(인접 행렬, 인접 리스트)를 공부할 수 있었다.  