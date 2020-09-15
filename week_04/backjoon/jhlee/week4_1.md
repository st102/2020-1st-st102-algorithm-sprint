# 백준 10026 <적록색약>

##문제 설명
적록색약과 정상인이 판별하는 그룹의 개수를 출력하라.


## 나의 풀이법
```c++

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

string str[101];
string colorStr[101];
int n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool check[101][101];

void bfs(int a, int b, string *s) {
	queue<pair<int, int>> q;
	q.push(make_pair(a,b));
	check[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!check[nx][ny] && s[x][y] == s[nx][ny]) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
		}
	}
}
** bfs 탐색을 사용하였다. 시작 위치와 문자열을 입력받아 이를 바탕으로 탐색을 진행하였다.
** 문자열 입력을 받지 않는다면 함수를 2개 사용해야하기 때문에 이와 같이 작성하였다.


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int normal = 0;
	int disability = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (str[i][j] == 'G')
				colorStr[i] += 'R';
			else
				colorStr[i] += str[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				normal++;
				bfs(i, j, str);
			}
		}
	}

	for (int i = 0; i < n; i++)
		memset(check[i], false, sizeof(bool)*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				disability++;
				bfs(i, j, colorStr);
			}
		}
	}

	cout << normal << ' ' << disability << '\n';

	system("pause");
	return 0;
}
** 문자열을 입력받고 이후 이를 바탕으로 적록색약이 있는 사람이 보는 문자열을 지정
** 이후 bfs 함수를 통해 세주었다.



## 다른 사람 풀이법
```c++

#include<iostream>
#include<cstring>
#include<queue>
 
#define endl "\n"
#define MAX 100
using namespace std;
 
int N;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (Visit[nx][ny] == false)
                {
                    if (MAP[nx][ny] == MAP[x][y])
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}
** bfs 함수로 나와 동일하다.

void Solution()
{
    int Answer, Answer2;
    Answer = Answer2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Visit[i][j] == false)
            {
                BFS(i, j);
                Answer++;
            }
        }
    }
 
    memset(Visit, false, sizeof(Visit));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j] == 'G') MAP[i][j] = 'R';
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Visit[i][j] == false)
            {
                BFS(i, j);
                Answer2++;
            }
        }
    }
 
    cout << Answer << " " << Answer2 << endl;
}
** 나와 같은 방식으로 진행을 하였다.
 
void Solve()
{
    Input();
    Solution();
}
** input 함수를 통해 문자열 입력받고 solution 함수 호출

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
** 메인 함수 solve() 함수 호출



