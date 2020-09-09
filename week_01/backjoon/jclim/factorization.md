# 소인수분해

## 문제 설명

* 정수 `N`이 주어졌을 때, `N`의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력하는 문제

## 나의 풀이 방법

```c++
#include <iostream>

using namespace std;

int num;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;

	int i = 2;

	while (num > 1) {
		while (num % i == 0) {
			cout << i << "\n";
			num /= i;
		}

		i++;
	}
}
```

> 정수를 입력받아 `num`에 저장하고 `i`를 1씩 올려가면서 나눌수 없을 때까지 나누고 값을 출력한다.  
> `num`이 1이 되면 반복문을 종료했다.  

## 다른 사람의 풀이 방법

```c++
#include <iostream>

using namespace std;

int num;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;

	for (int i = 2; i * i <= num; i++) {
		while (num % i == 0) {
			cout << i << "\n";
			num /= i;
		}
	}

	if (num > 1) cout << num << "\n";
}
```

> 이 풀이에서는 반복의 조건이 조금 다른데 `i * i <= num`을 만족할때 까지 반복한다.  
> 만일 제곱근보다 큰 약수가 있다면, 그 약수로 나눈 몫은 제곱근보다 작을 것이기 때문에 그 이전에 이미 나누어보았을 것이다.  
> 이전에 이미 나누어본 부분을 확인하지 않기 때문에 처음의 코드보다 더 빠르게 동작한다.  

## 배운점
> 처음에 1도 출력을 해야 한다고 생각을 했는데 소수가 아닌 수 1의 소인수는 없다는 사실을 알았다.  
> 소인수분해를 할 때 `1~N` 사이의 숫자로 모두 나눠보지 않아도 `N`의 제곱근보다 작은 숫자만으로 소인수분해가 가능하다는 걸 알 수 있었다.