# 백준 신입사원 <1946>

## 문제 설명
사원에 대해 두 성적을 입력 받을 때 어떤 한 사원이 두 성적 모두 떨어지지만 않으면 뽑는다 할 때의 사원 수를 출력하라. 이때 중복된 순위는 없다.


## 나의 풀이법
```c++

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> salesman;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testcase;
	cin >> testcase;

	while (testcase != 0) {
		int n;
		cin >> n;

		int loser = 0;
		for (int i = 0; i < n; i++) {
			int rank1, rank2;
			cin >> rank1 >> rank2;

			salesman.push_back(make_pair(rank1, rank2));
		}
		sort(salesman.begin(), salesman.end());

		for (int i = n-1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (salesman[i].second > salesman[j].second) {
					loser++;
					break;
				}
			}
		}
		cout << n - loser << '\n';

		salesman.clear();
		testcase--;
	}

	system("pause");
	return 0;
}
** 중복된 순위는 없다고 하였으므로 첫번째 순위에 대해 정렬을 한 후 나머지 한 순위에 대해서만 비교해 주어 풀었다.




## 다른 사람 풀이
``` c++

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int get_min(int a, int b) { return a < b ? a : b;}

int main() {

    int t, a, b, i, j, k, n;
    vector<pair<int, int> > v;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        v.clear();

        for (j = 0; j < n; j++) {
            scanf("%d %d", &a, &b);
            v.push_back(make_pair(a, b));
        }

        sort(v.begin(), v.end(), comp);
        int cnt = n;
        int bound = v[0].second;

        for (k = 1; k < n; k++) {
            if (v[k].second > bound) cnt--;
            bound = get_min(bound, v[k].second);
        }

        printf("%d\n", cnt);
    }

    return 0;
}
** 이사람 또한 하나의 순위에 대해서 정렬을 해주어 풀었다. 이후 나와는 비교되게 반복문을 하나만 사용해서 비교해 주었다. 이 방식이 훨씬 더 효율이 좋다는 것을 느꼈다.


## 반성할 점
처음에 십만이란 크기를 생각 안하고 첫 번째 순위와 두 번째 순위에 대해서 반복문을 통해 비교 하며 진행하느라 시간초과가 나왔었다.



