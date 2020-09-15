# 백준 4796 <캠핑>

## 문제 설명
캠핑을 하는데 주어진 입력에 따라 지낼 수 있는 가장 최대의 캠핑 수를 출력하라.


## 나의 풀이법
```c++

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int l, p, v;
	int counts = 1;

	cin >> l >> p >> v;

	while (1) {
		if (l == 0 && p == 0 && v == 0)
			break;

		long ans = 0;

		int quotient = v / p;
		int remainder = min(v % p, l);
		ans = l * quotient + remainder;

		cout << "Case " << counts << ": " << ans << '\n';

		cin >> l >> p >> v;
		counts++;
	}

	system("pause");
	return 0;
}
** 수식을 통해 해결하였다.



##다른 사람 풀이법
```c++

#include<iostream>

using namespace std;

int main()

{

	int L, P, V, ans,cnt=1;

	while (true)

	{

		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0)

			break;

		else

		{

			if (P < V)

			{

				int one, two;

				one = V / P*L;

				two = V%P > L ? L : V%P;

				ans = one + two;

				cout << "Case "<<cnt++<<": " << ans << endl;

			}

		}

	}

	return 0;

}
** 나와 동일하지만 min을 구하는 부분에서 3항 연산자를 사용하였다.


## 반성할 점 및 배운점
** 처음에 다양한 경우의 수를 생각하지 않고 reaminder에서 v%p로 설정하였었다. 테스트 케이스 이외에도 다양한 경우의 수를 생각하자.
