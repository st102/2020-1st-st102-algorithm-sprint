# 연구소

## 문제 설명

* 연구소에 3개의 벽을 세우고 상하좌우로 바이러스가 퍼졌을 때 안전 영역 크기의 최댓값을 구하는 문제

## 나의 풀이 방법

```c++
void count_safe(int w1, int w2, int w3) {
	if (board[w1 / col][w1 % col] != 0) return;
	if (board[w2 / col][w2 % col] != 0) return;
	if (board[w3 / col][w3 % col] != 0) return;

	int temp_board[8][8];
	copy(&board[0][0], &board[0][0] + 8 * 8, &temp_board[0][0]);

	temp_board[w1 / col][w1 % col] = 1;
	temp_board[w2 / col][w2 % col] = 1;
	temp_board[w3 / col][w3 % col] = 1;

	queue<pair<int, int>> q;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (temp_board[i][j] == 2) q.push({ j, i });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= col || ny >= row) continue;		
			if (temp_board[ny][nx] != 0) continue;

			temp_board[ny][nx] = 2;

			q.push({ nx, ny });
		}
	}

	int cnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (temp_board[i][j] == 0) cnt++;
		}
	}

	answer = max(answer, cnt);
}
```

> 정수 3개를 인자로 받아 각 위치에 벽을 세운다. 이후 BFS를 사용하여 바이러스를 상하좌우로 퍼뜨리고 안전 영역의 수를 세어 answer 변수의 최댓값을 갱신한다.

```c++
int main(int argc, char** argv)
{
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < row * col - 2; i++) {
		for (int j = i + 1; j < row * col - 1; j++) {
			for (int k = j + 1; k < row * col; k++) {
				count_safe(i, j, k);
			}
		}
	}

	cout << answer << endl;
}
```

> 반복문을 사용해 count_safe 함수를 호출하면서 벽 3개를 세우는 모든 경우의 수를 확인했다.


## 다른 사람의 풀이 방법

```c++
void B_T(int n, int m, int depth) {

	if (depth >= MAX_WALL){	// 벽 개수 다 쓰면 탈출, 갱신
		update();
		return;
	}

	for (int i = n; i < N; i++) {
		// 다음 줄부터는 x=0부터 for문
		for (int j = (i==n)?m:0; j < M; j++) {
			// 맨 처음 호출 안함
			if (depth !=0 && i == n && j == m)
				continue;
			// 벽 세우고 호출
			if (map[i][j] == 0) {
				wall[depth].Y = i;
				wall[depth].X = j;
				B_T(i, j, depth+1);
			}
		}
	}
}
```

> 이 풀이에서는 반복문 대신 재귀함수를 사용하여 벽을 세우는 모든 경우를 확인한다.  
> `depth`를 통해 벽의 개수를 세고 3개가 되면 바이러스를 퍼뜨리는 함수를 호출하고 재귀를 종료한다.  

## 배운점
> 완전탐색을 통해 모든 경우의 수를 확인하는 풀이를 알 수 있었다.  
> `copy` 함수를 사용할 때 원본 배열의 전체 크기를 입력하지 않고 사용중인 크기를 입력하면 정상적으로 동작하지 않는 것을 알게되었다.  