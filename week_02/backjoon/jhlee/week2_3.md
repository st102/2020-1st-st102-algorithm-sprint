# 백준 1912 <연속합>

## 문제 설명
연속하는 수열의 합이 최대가 되는 값을 출력


## 나의 풀이법
```c++

int list[100001];
int dp[10001];
int n;
cin >> n;

for (int i = 0; i < n; i++) cin >> list[i];

dp[0] = list[0];

for (int i = 1; i < n; i++) {
	if (dp[i - 1] + list[i] > list[i])
		dp[i] = dp[i - 1] + list[i];
	else
		dp[i] = list[i];
}

int result = dp[0];

for (int i = 1; i < n; i++) result = max(result, dp[i]);

cout << result << '\n';

** 다이나믹 프로그래밍 방식으로 풀이
** 해당 인덱스에서 전 수열을 합친 것과 안 합친 것의 크기 비교하여 더 큰 것 선택한 후 배열에 저장
** 이후 위의 값 저장된 배열 중 가장 큰 값을 출력


## 다른 사람 풀이
``` c++

for(int i=1;i<=n;i++)
	cin >> dp[i];
		
int max = dp[1];

for(int i=2;i<=n;i++) {		
	if (dp[i-1] > 0 && dp[i] + dp[i-1] > 0) {
		dp[i] += dp[i-1];
	} 
			
	if (max < dp[i]) {
		max = dp[i];
	}
		
}

** 변수를 하나만 사용하고 반복문 하나만으로 끝냈다.
** 전 값과 현재 값이 0보다 크다면 더하고 이 중 가장 큰 값을 출력하는 방식
** 동일하게 DP 방식이지만 풀이에 전체적인 흐름은 같지만 사소한 부분에서 살짝 다르다.


## 배운점
십만 이상일 때는 2중 for문을 사용하지 못한다.


