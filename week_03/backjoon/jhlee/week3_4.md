# 백준 파티 <1238>

## 문제 설명
각각의 노드에서 목표 노드까지 최소값으로 가는 비용 중 가장 큰 비용을 출력하라.


## 나의 풀이법
```c++

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000000
#define MAX_NODE 1001

int N, M, X;
int dist[MAX_NODE];
vector<pair<int, int>> v[MAX_NODE];

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int index = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (dist[index] < distance)
			continue;

		for (int i = 0; i < v[index].size(); i++) {
			int nextIndex = v[index][i].first;
			int nextDist = distance + v[index][i].second;

			if (nextDist < dist[nextIndex]) {
				dist[nextIndex] = nextDist;
				pq.push(make_pair(nextIndex, -nextDist));
			}
		}
	}
}
** 다익스트라 방식이다. 시작점을 입력으로 받으면 그 값을 기준으로 각 노드로 가는 최소비용을 구해준다.


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> X;
	int keyX[MAX_NODE] = { 0, };

	for (int i = 1; i <= N; i++)
			dist[i] = INF;
	
	for (int i = 0; i < M; i++) {
		int start, end, coast;
		cin >> start >> end >> coast;

		v[start].push_back(make_pair(end, coast));
	}
	int answer = 0;

	dijkstra(X);
	copy(dist, dist + N + 1, keyX);

	for (int i = 1; i <= N; i++) {
		if (X == i)
			continue;
		for (int j = 1; j <= N; j++) 
			dist[j] = INF;

		dijkstra(i);
		answer = max(answer, dist[X] + keyX[i]);
	}

	cout << answer << '\n';
	
	system("pause");
	return 0;
}
** 입력을 받은 후 모든 노드들에서의 접근을 해야하므로 총 N번 다익스트라 실행을 해주었다.



## 다른 사람 풀이법
``` c++

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
 
#define endl "\n"
#define MAX 1010
#define INF 987654321
using namespace std;
 
int N, M, X, Answer;
int Dist[MAX], Res[MAX];
vector<pair<int,int>> V[MAX];
 
void Input()
{
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        V[a].push_back(make_pair(b, c));
    }
}
** 사용자 입력을 받는 함수


void Dijkstra(int Start)
{
    priority_queue<pair<int, int>> PQ;
    Dist[Start] = 0;
    PQ.push(make_pair(0, Start));
 
    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
 
        for (int i = 0; i < V[Cur].size(); i++)
        {
            int Next = V[Cur][i].first;
            int nCost = V[Cur][i].second;
 
            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
 
}
** 다익스트라 함수

 
void Solution()
{
    for(int i = 1; i <= N; i++)
    { 
        for (int j = 1; j <= N; j++) Dist[j] = INF;
        Dijkstra(i);
        Res[i] = Dist[X];        
    }
    for (int j = 1; j <= N; j++) Dist[j] = INF;
    Dijkstra(X);
    for (int i = 1; i <= N; i++) Res[i] = Res[i] + Dist[i];
    sort(Res + 1, Res + N + 1);
    Answer = Res[N];
}
** 거리를 초기화 하는 동시에 다익스트라 함수를 호출해 주었다.

 
void Solve()
{
    Input();
    Solution();
    cout << Answer << endl;
}
** 해결 함수

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
** 메인 함수 



## 배운점
** 다익스트라 함수에 대해서 배우며 구현해 보았다.







