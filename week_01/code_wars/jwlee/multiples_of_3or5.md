Multiples of 3 or 5

나의 풀이 방법

#include <iostream>
#include <string>

using namespace std;

int main() {

	int input;
	int sum=0;
	cin >> input;

	if (input < 0) { cout << 0; }


	for (int i = 1; i < input ;i++) {

		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}

	}
	cout << sum;
}

- 음수는 0을 출력하도록 했고 i가 1부터 input 까지 증가하면서 3이나 5의 약수이면 sum에 저장한다. 

다른 사람의 풀이 방법

int solution(int number)
{
  int sum = 0;
  for (int n = 3; n < number; n++) {
    if ((n%3 == 0) || (n%5 == 0))
      sum += n;
  }
  return sum;
}

- 생각해보니까 i가 1부터 시작할 필요가 없었다. 

배운 점

- 처음에 생각한 코드는 저게 아니었는데, 종이에 직접 천천히 써보니까 훨씬 간단해졌다. 종이에 정리하는 것도 좋은 방법같다. 

반성할 점

- 더 빨리 푸는 연습을 해야겠다.
