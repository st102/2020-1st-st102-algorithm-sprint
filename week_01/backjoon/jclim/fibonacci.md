# 피보나치 수 5

## 문제 설명

* `n`이 주어졌을 때, `n`번째 피보나치 수를 구하는 문제

## 나의 풀이 방법

```c++
#include <iostream>
#include <cmath>

using namespace std;

int N;

int main(int argc, char** argv)
{
	cin >> N;
	cout << (pow(((1 + sqrt(5)) / 2), N) - pow(((1 - sqrt(5)) / 2), N)) / sqrt(5) << endl;
}
```

> 피보나치 수열의 일반항을 사용하여 n번째 피보나치 수를 구하였다.

> ![latex](https://latex.codecogs.com/gif.latex?a_%7Bn%7D%3D%5Cfrac%7B1%7D%7B%5Csqrt%7B5%7D%7D%5Cleft%20%5C%7B%20%5Cleft%20%28%20%5Cfrac%7B1&plus;%5Csqrt%7B5%7D%7D%7B2%7D%20%5Cright%20%29%20%5E%20%7Bn%7D%20-%20%5Cleft%20%28%20%5Cfrac%7B1-%5Csqrt%7B5%7D%7D%7B2%7D%20%5Cright%20%29%20%5E%7Bn%7D%20%5Cright%20%5C%7D)

> 위 방식을 사용하면 시간 복잡도 `O(1)`으로 구할 수 있지만 n의 크기가 조금만 커져도 오버플로우가 발생한다.  
> n의 크기가 클 경우 DP를 사용하여 구하는게 좋을 것 같다.

## 다른 사람의 풀이 방법

```c++
#include <iostream>

using namespace std;

int N;
int dp[21] = { 0,1 };

int main(int argc, char** argv)
{
	cin >> N;

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N] << endl;
}
```

> DP를 사용하여 피보나치 수를 구하는 풀이이다.  
> dp 배열의 0, 1번째 인덱스를 0, 1로 초기화하고 2번째 인덱스부터 `dp[i] = dp[i - 1] + dp[i - 2]`의 규칙으로 값을 채운다.  
> 시간 복잡도는 `O(n)`이고 일반항을 사용한 풀이보다 n의 크기가 커도 정상적으로 값을 출력한다.

## 배운점
피보나치 수를 구하는 다양한 방법(수열의 일반항을 이용한 방법, DP를 이용한 방법)을 알 수 있었다.