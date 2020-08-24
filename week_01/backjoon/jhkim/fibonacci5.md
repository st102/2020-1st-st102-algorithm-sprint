피보나치수5
===========

## 문제 설명

20보다 작거나 같은 자연수 또는 0인 n번째 피보나치 수 출력


## 나의 풀이 방법

```c++
#include <iostream>

using namespace std;

int main() {
	int n;
	int dp[20] = { 0 };
	
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;

	return 0;
}
```

> DP를 사용해 반복문을 통해서 피보나치 수를 구하였습니다.
> 피보나치 공식인 dp[i] = dp[i-1] + dp[i-2]를 사용하였습니다.
> 이 방법을 사용하면 시간 복잡도는 O(N) 입니다.

## 다른 사람의 풀이 방법

```c++
#include <cstdio>
int fibo(int num) {
    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    return fibo(num-2) + fibo(num-1);
}
int main() {
    int num;
    scanf("%d",&num);
    printf("%d",fibo(num));
}
```

> 똑같이 DP를 사용하였지만 재귀를 이용해서 문제를 푸는 방식입니다.
> 참고:https://cryptosalamander.tistory.com/37

## 배운 점

> DP를 사용해서피보나치 수를 구하는데에는 반복문과 재귀가 쓰인다는 것을 알게 되었습니다.
> 피보나치 수열을 구하는 효율적인 방법을 찾아보니 다음과 같이 3가지 방법을 알게 되었습니다.
1. 무작정 연산-> O(n)
2. 행렬을 이용한 연산 -> O(logn)
3. 일반항을 이용한 연산 

