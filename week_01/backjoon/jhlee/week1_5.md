# 백준 10942 <팬린드롬>

## 문제 설명
팬린드롬이란 서로 대칭인 수열을 뜻한다.
팬린드롬인 경우 1, 아닌 경우 0을 출력해라 


# 나의 풀이법
```c++

for (int i = 1; i <= n; i++) dp[i][i] = 1;

for (int i = 1; i < n; i++) {
	if (list[i] == list[i + 1])
		dp[i][i + 1] = 1;
	else
		dp[i][i + 1] = 0;
}
-> 입력 받은 수열 초기화 작업

for (int i = 2; i < n; i++) {
	for (int j = 1; i + j <= n; j++) {
		if (list[j] == list[i + j] && dp[j + 1][i + j - 1] == 1)
			dp[j][i + j] = 1;
		else
			dp[j][i + j] = 0;
	}
}
-> 양 끝쪽 추가하는 방식으로 dp 진행


## 반성할 점
for (int pp = 0; pp < m; pp++) {
	int start, end;
	int check = 1;
	cin >> start >> end;
	int len = end - start + 1;

	for (int i = 0; i < len / 2; i++) {
		if (list[start + i] != list[end - i]) {
			cout << 0 << '\n';
			check = 0;
			break;
		}
	}

	if (check == 1)
		cout << 1 << '\n';
}
-->> 입력 배열이 2000이라 해서 하나씩 비교해도 충분히 가능할 것이라 생각해서 위와 같이 짰는데 시간초과 나왔다.
입력의 크기 뿐만 아니라 입력의 개수도 생각했어야 했다.



