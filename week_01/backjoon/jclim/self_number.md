# 셀프 넘버

## 문제 설명

* 10000보다 작거나 같은 셀프 넘버를 한 줄에 하나씩 출력하는 문제

## 나의 풀이 방법

```c++
void self(bool* arr, int index)
{
	if (arr[index] == false) return;

	int sum = index;
	while (index) {
		sum += index % 10;
		index = index / 10;
	}

	if (sum > 10000) return;

	self(arr, sum);
	arr[sum] = false;
}
```

> sum에 index와 index의 각 자리수를 더하고 재귀 호출을 통해 sum이 10000을 초과할 때 까지 반복한다.  
> sum은 셀프 넘버가 아니므로 재귀 호출이 종료되면서 arr[sum]을 false로 채운다.  
> arr[index] == false일 경우 이미 확인한 숫자이므로 함수를 종료한다.  

```c++
int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool arr[10001];
	fill_n(arr, 10001, true);

	for (int i = 1; i <= 10000; i++) {
		self(arr, i);
	}

	for (int i = 1; i <= 10000; i++) {
		if (arr[i]) cout << i << "\n";
	}
}
```

> self 함수를 호출해 1부터 10000까지 셀프 넘버인지 확인하고 셀프 넘버일 경우 해당 숫자를 출력했다.

## 다른 사람의 풀이 방법

```c++
#include <stdio.h>

int main() {

	int num;
	int i,j;
	int sum;
	int number[20001] = { 0, };

	for (i = 1; i <= 10000; i++)
	{
		num = i;
		sum = 0;
		while (true) {
			sum += num % 10;
			num = num / 10;
			if (num == 0) {
				break;
			}
		}
		number[sum+i] = 1;
	}
	for (i = 1; i <= 10000; i++)
	{
		if (number[i] == 0)
		{
			printf("%d\n", i);
		}
	}
}
```

> 이 풀이에서는 재귀 함수를 사용하지 않고 각 숫자마다 한번씩 규칙에 따라 계산하고 셀프넘버인지 확인한다.  

## 배운점
> 재귀 함수를 통해 구현을 했었는데 더 간단하게 구현할 수 있는 방법을 알 수 있었다.