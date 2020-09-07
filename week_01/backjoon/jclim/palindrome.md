# 팰린드롬?

## 문제 설명

* 자연수 N개를 입력받고 두 정수 S와 E가 주어질 때마다 S번째 수부터 E번째 까지 수가 팰린드롬을 이루는지 출력하는 문제

## 나의 풀이 방법

```c++
int palindrome(int s, int e) {
	int cnt = 0;

	for (int i = 0; i < (e - s + 1) / 2; i++) {
		if (dp[s + i][e - i]) break;
		if (arr[s + i] != arr[e - i]) return 0;
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		dp[s + i][e - i] = true;
	}

	return 1;
}
```

> 정수 s와 e를 인자로 받아 s~e 구간의 수가 팰린드롬을 이루는지 확인하는 함수다.  
> dp 배열에는 해당 구간이 팰린드롬인지 아닌지 저장한다.  
> 구간의 양쪽 끝부터 1칸씩 좁히면서 dp 배열을 확인해 해당 구간이 팰린드롬이거나 가운데에 도달할 때까지 숫자가 같으면 참을 반환한다.  
> 참을 반환할 경우에는 확인한 구간의 dp 배열을 true로 채워 나중에 같은 구간을 중복해서 확인할 필요가 없도록 한다.

```c++
int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
	}

	cin >> questions;

	for (int i = 0; i < questions; i++) {
		int s, e;
		cin >> s >> e;
		cout << palindrome(s, e) << "\n";
	}
}
```

> N개의 자연수와 구간을 입력받아 팰린드롬을 이루는지 출력한다.

## 다른 사람의 풀이 방법

```c++
int palin(int s, int e) {
	if (s >= e) {
		return 1;

	}
	int& ret = cache[s][e];
	if (ret != -1) return ret;

	if (board[s] == board[e]) {
		return ret = palin(s + 1, e - 1);
	}
	else { return 0; }
}
```

> 이 풀이에서는 반복문이 아닌 재귀 함수를 사용하여 특정 구간의 수가 팰린드롬을 이루는지 확인한다.  

## 배운점
> 처음에 제출했을 때 시간초과가 났다.  
> 그 이유는 입출력에 있었는데 개행을 할 때 `std::endl`보다 `'\n'`을 사용하는 것이 더 빠르다고 한다.  
> 실제로 `std::endl`대신 `'\n'`을 사용하니 통과를 했다.  

> 그리고 `std::cout`+`std::endl`, `std::cin` < `printf`, `scanf` < `std::cout`+`\n`, `std::cin` 순으로 속도가 빨랐다.  
> 입출력 속도도 시간초과에 영향을 미칠만큼 영향력을 준다는 것을 체감할 수 있었다.  