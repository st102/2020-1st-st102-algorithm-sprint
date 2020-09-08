유기농 배추
=========

## 문제 설명

그래프에서 배추에 필요한 최소의 지렁이 수 구하기. 지렁이는 상하좌우로 움직일 수 있으며 한 집단의 배추에는 하나의 지렁이만 필요하다. 


## 나의 풀이 방법

```c++
void dfs(int x, int y, int cnt)
{
    if (x < 0 || y < 0 || x >= row || y >= col)
        return;
    worm_num[x][y] = cnt;

    for (int k = 0; k < DIRECTION_NUM; k++) {
        int nx = x + xpos[k];
        int ny = y + ypos[k];
        if (nx < 0 || ny < 0 || nx >= row || ny >= col)
            continue;
        if (graph[nx][ny] == 1 && worm_num[nx][ny] == 0) {
            dfs(x + xpos[k], y + ypos[k], cnt);
        }
    }
}
```
**DFS**를 이용하여 그래프 전체를 탐색하는데 배추가 있고(graph배열이 1인 경우) 방문하지 않은 경우(wormNum배열이 0인 경우) main 함수에서 탐색을 시작한다. dfs배열에는 조건에 해당하면 wormNum배열에 지렁이 수(cnt)를 넣는다. 그리고 상하좌우를 확인해서 아까와 동일하게 탐색 가능하다면 dfs로 탐색하도록한다. 


## 다른 사람의 풀이 방법
```c++
void bfs(int y, int x)
{
	check[y][x] = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && nx < m && ny < n) {
				if (graph[ny][nx] == 1 && check[ny][nx] == 0)
				{
					q.push({ ny,nx });
					check[ny][nx] = 1;
				}
			}
		}
	}
	
}
```
이 풀이 방법은 동일하게 전체 그래프를 확인하는 대신 **BFS**를 이용하여 조건이 된다면 탐색을 하는 방법을 사용했다.  

참고 사이트: <https://jow1025.tistory.com/87>


## 배운점 

-이 문제는 BFS와 DFS를 활용해서 모두 풀 수 있는 문제다. 


## 반성할 점

-다시 생각해보니 graph배열 하나로도 충분히 최소 지렁이 수를 저장할 수 있을 것 같다. 