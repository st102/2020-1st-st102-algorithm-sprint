# 백준 2563 <색종이>

## 문제 설명 
100x100 크기의 도화지에 10x10 색종이를 붙일 때 붙여진 색종이의 넓이를 구하여라.


## 나의 풀이법
```c++

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int x, y;
	bool check[100][100];
	int answer = 0;

	for (int i = 0; i < 100; i++)
		memset(check[i], false, sizeof(bool) * 100);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		for (int s = x; s < x + 10; s++) {
			for(int t = y; t < y + 10; t++)
				if(!check[s][t]) check[s][t] = true;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			if (check[i][j]) answer++;
	}

	cout << answer << '\n';
	
	system("pause");
	return 0;
}
** 왼쪽 아래 꼭지점을 입력 받을 때마다 한변의 길이가 10이므로 bool형 배열에 체킹을 해준다.
** 이는 겹쳐졌을 때도 고려하여 체킹된 개수를 세어 출력해주었다.


## 다른 사람 풀이법
``` C

#include <stdio.h> 
int main() { 
	int arr[101][101] = { 0, }; 
	int t; 
	int cnt=0; 
	scanf("%d", &t); 
	while (t--) { 
		int a, b; 
		scanf("%d %d", &a, &b); 
		for (int i = 0; i < 10; i++) { 
			for (int j = 0; j < 10; j++) { 
				arr[a + i][b + j] = 1; 
			} 
		} 
	} 
	for (int i = 0; i < 100; i++) { 
		for (int j = 0; j < 100; j++) { 
			if (arr[i][j] == 1)cnt++; 
		} 
	} 
printf("%d", cnt); 
return 0; 
}

** 이 사람의 풀이법을 참고하여 풀었었다. 이 사람은 int형으로 체킹을 해주었고 나는 bool형으로 체킹하였다.


## 반성한 점
* 처음에 정사각형이 겹치는 것을 생각하며 각 정사각형이 겹쳐질 때 겹쳐진 사각형의 크기를 빼는 식으로 구현하였는데 이 방법은 하나의 사각형에 여러 사각형이 포함되어 있을 때를 고려하지 않은 방식이었다. 그래서 다른 사람의 풀이를 참고하였다.

