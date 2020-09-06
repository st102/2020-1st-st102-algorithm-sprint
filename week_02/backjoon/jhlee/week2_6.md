# 백준 7568 <덩치>

## 문제 설명
키와 몸무게 모두 클 경우 덩치가 크다고 한다. 이때 각 인덱스 별로 덩치가 큰 순위를 출력해라.

## 나의 풀이법
```c++

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> info;
int result[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int weight, height;
		cin >> weight >> height;

		info.push_back(pair<int, int>(weight, height));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (info[i].first < info[j].first && info[i].second < info[j].second)
				result[i]++;
		}
	}

	for (int i = 0; i < n; i++) cout << result[i] + 1 << ' ';
	cout << '\n';

	system("pause");
	return 0;
}
** 각 인덱스마다 입력 받은 몸무게와 키에 대해서 이중 반복문을 통해 다른 인덱스와 일일히 비교해 주었다. 
** 이때 키와 몸무게 모두 작다면 rank를 1 더해주었고 0값에서 시작하므로 출력할 때는 1을 더해주었다.



## 다른 사람 풀이
```c++

pair<int, int>people[50];
int Rank[50];
 
void compareRank(const int N) {
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            if (people[i].first > people[j].first && people[i].second > people[j].second)
                Rank[j]++;
        }
    }
}
 
void printRank(const int N) {
    for (int i = 0;i < N;i++) {
        cout << Rank[i] + 1 << " ";
    }
}
 
int main() {
    int N;
    cin >> N;
    for (int i = 0;i < N;i++) {
        cin >> people[i].first >> people[i].second;
    }
 
    compareRank(N);
    printRank(N);
 
    return 0;
}
** 내가 푼 방식인 이중 반복문을 통해 순위를 더해주는 기능과 이를 출력해주는 부분을 함수로 나누어준 점을 빼면 동일하게 풀었다. 
** 이 사람의 변수명(info보다 people)이 더 직관적이고 좋은 것 같다.


