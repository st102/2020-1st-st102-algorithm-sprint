# 백준 단지번호 붙이기 <2667>

## 문제 설명
단지를 입력하고 총 단지 수와 단지 내 집의 수를 출력하라


## 나의 풀이법
```c++
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define MAX_LEN 25

int n;
string map[MAX_LEN];
int result[MAX_LEN*MAX_LEN];
bool check[MAX_LEN][MAX_LEN];
int answer = 0;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool checkSize(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < n)
		return true;
	else
		return false;
}

void dfs(int x, int y) {
	check[x][y] = true;
	result[answer]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (checkSize(nx, ny)) {
			if (!check[nx][ny] && map[nx][ny] == '1') dfs(nx, ny);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> map[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && !check[i][j]) {
				dfs(i, j);
				answer++;
			}
		}
	}

	sort(result, result + answer);

	cout << answer << '\n';
	for (int i = 0; i < answer; i++) cout << result[i] << '\n';

	system("pause");
	return 0;
}
** 단지를 입력 받고 하나씩 탐색하며 1인 경우 dfs 방식으로 체킹해주어 단지의 총 수를 구하고 각 단지내 집의 수를 세주었다. 매직넘버 및 decompose condition을 사용하려고 해보았다.



## 다른 사람 풀이법
``` c++

#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
 
#define MAX_SIZE 25
 
using namespace std;
 
int n;
int num_of_houses[MAX_SIZE * MAX_SIZE] = { 0, };
int house_number = 0;
int map_data[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
 
 
// 우,하,좌,상
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
 
 
// BFS
void bfs(int y, int x) {
 
    queue< pair<int, int> > q; // 이용할 큐, (x,y) -> (행, 열)
    q.push(make_pair(y, x)); // pair를 만들어서 queue에 넣습니다.
 
    // 처음 x,y를 방문 했기때문에
    visited[y][x] = true;
    num_of_houses[house_number]++;
 
    while (!q.empty()) {
 
        // 큐의 현재 원소를 꺼내기
        y = q.front().first;
        x = q.front().second;
        q.pop();
 
        // 해당 위치의 주변을 확인
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            // 지도를 벗어나지 않고
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                // 집이면서 방문하지 않았다면 -> 방문
                if (map_data[ny][nx] == 1 && visited[ny][nx] == false) {
                    visited[ny][nx] = true;
 
                    // 해당 단지의 집의 수를 증가시킴
                    num_of_houses[house_number]++;
 
                    // 큐에 현재 nx,ny를 추가
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}
 
int main() {
    scanf("%d", &n);
 
    // 지도 데이터 입력
    for (int col = 0; col < n; col++) {
        for (int raw = 0; raw < n; raw++) {
            scanf("%1d", &map_data[col][raw]);
        }
    }
 
    // 전체의 지도 데이터를 하나하나 체크
    for (int col = 0; col < n; col++) {
        for (int raw = 0; raw < n; raw++) {
            // 집이 존재하고, 방문하지 않았을 때,
            if (map_data[col][raw] == 1 && visited[col][raw] == false) {
                house_number++;
 
                // bfs 탐색 진행
                bfs(col, raw);
            }
        }
    }
 
    // 오름차순으로 정렬
    sort(num_of_houses + 1, num_of_houses + house_number + 1);
 
    // 출력
    printf("%d\n", house_number);
    for (int i = 1; i <= house_number; i++) {
        printf("%d\n", num_of_houses[i]);
    }
    return 0;
}
** 나와 bfs 방식이냐 dfs 방식이냐만 빼고 모든 것이 동일하였다.



