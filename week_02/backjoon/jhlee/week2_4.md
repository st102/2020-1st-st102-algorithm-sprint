# 백준 1012 <유기농 배추>

## 문제 설명
값이 1인 인접해 있는 셀들의 집합의 개수를 구하여라.


## 나의 풀이법
```c++
 
int test_case;
cin >> test_case;				// 테스트 케이스 입력

for (int t = 0; t < test_case; t++) {
	int k;
	cin >> m >> n >> k;			// 가로행 세로행 입력
	int answer = 0;

	for (int i = 0; i < 50; i++) {		// 배열 초기화
		memset(cabbage[i], 0, sizeof(int) * 50);
		memset(check[i], false, sizeof(bool) * 50);
	}
	for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;

			cabbage[x][y] = 1;
	}

	for (int i = 0; i < m; i++) {		// 값이 1일 셀 선택하여 인접해 있는 셀들 모두 check=true로 바꾼다.
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && cabbage[i][j] == 1) {
				dfs(i, j);
				answer++;
			}
		}
	}
		
	cout << answer << '\n';
}


void dfs(int x, int y) {		
	check[x][y] = true;

	for (int q = 0; q < 4; q++) {
		int nx = x + dx[q];
		int ny = y + dy[q];

		if (0 <= nx && nx < m && 0 <= ny && ny < n) {
			if (!check[nx][ny] && cabbage[nx][ny] == 1)
				dfs(nx, ny);
		}
	}
}
// 입력으로 들어온 값 true로 바꿔주고 이와 인접해 있는 배추에 dfs 방식으로 이동하게 해주었다.




## 다른 사람 풀이법

int map[50][50];
int check[50][50];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int m, n, k;

//가로, 세로,배추위치갯수
void bfs(int y,int x);

int main()
{
	int t;
	cin >> t;
	int x, y;
	while (t--)
	{
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		cin >> m >> n >> k;
		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			//좌표조심
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1 && check[i][j] == 0)
				{
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}

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
				if (map[ny][nx] == 1 && check[ny][nx] == 0)
				{
					q.push({ ny,nx });
					check[ny][nx] = 1;
				}
			}
		}
	}
}

** 나와 checking 해주는 방식이 bfs이냐 dfs이냐만 다른 고 대부분의 흐름은 똑같다. 나도 bfs로 풀까하다 평소에 이러한 문제를 bfs로 많이 풀어 이번 문제는 dfs로 풀어보았다.



## 반성할 점
평소에 나한테 익숙한 x축이 행, y축이 열이 아니라 배열 인덱스 설정하는데 살짝 헷갈렸다. 그래서 결국 x-y 대칭으로 두어 문제를 풀었다. 


