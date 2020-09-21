# 백준 11047 <동전 0>

## 문제 설명
동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.


## 나의 풀이법
```c++

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int money[10];
	int n, k;
	int index;
	int answer = 100000001;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> money[i];
		if (money[i] <= k) index = i;
	}

	for (int i = index; i >= 0; i--) {
		int temp = 0;
		int goal = k;
		for (int j = i; j >= 0; j--) {
			int x = goal / money[j];
			temp += x;
			goal -= money[j] * x;

			if (goal == 0)
				break;
		}
		if (goal == 0)
			answer = min(answer, temp);
	}

	cout << answer << '\n';

	system("pause");
	return 0;
}
** 충분히 큰 수를 답으로 정해두고 동전을 입력받는다. 이때 가치의 합 K 이하인 최대의 동전 인덱스를 index에 저장한다. 
** 이중 반복문을 통해 동전의 합이 k가 되는 모든 경우의 수를 보면서 이때 최소의 값을 저장한다.


## 다른 사람 풀이
``` C

#include<stdio.h>
void main() {
	int i, n, m = 0, k, a[11]; scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = n; i > 0; i--) {
		m += k / a[i];
		k %= a[i];
	}
	printf("%d", m);
}
** 반복문 하나로 풀었다. 구글링 한 결과 대부분 이렇게 풀었다.
** 초반 나도 이런 생각을 하였는데 반례가 존재한다는 생각에 이중 반복문을 사용하였다.
5 900
1
10
50
300
500
과 같은 입력일 때 올바르지 못한 결과를 출력한다고 생각했는데
"i ≥ 2인 경우에 Ai는 Ai-1의 배수"과 같은 조건을 다 푼 후 보았다.


## 반성할 점
** 문제를 끝까지 잘 읽자는 교훈을 얻었다. 위 조건을 풀기 전 보았다면 더 간단하게 짰을 것 같다.


