 # Playing with digits

## 문제 설명

*   첫번째와 두번째 숫자가 주어진다. 첫번째 자릿수마다 두번째 숫자만큼 p제곱을 하며 1씩 늘어난 값들이 첫번째 주어진 값의 배수면
    몇배수인지 출력하고 배수가 아니면 -1을 출력한다.

## 나의 풀이 방법

```cpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class DigPow
{
public:
  static int digPow(int n, int p);
};
int DigPow::digPow(int n, int p) {
  vector<int> num_array;
  int copy_n = n;
  int resum = 0;
  int count = 0;
  while (copy_n != 0) {
    num_array.push_back(copy_n % 10);
    copy_n /= 10;
    count++;
  }
  count -= 1;
  for (int i = 0; i < num_array.size(); i++) {
    resum += pow(num_array[i],p+count);
    count--;
  }
  if (resum % n == 0) {
    return resum / n;
  }
  else return -1;
}

void testequal(int ans, int sol) {
    Assert::That(ans, Equals(sol));
}
void dotest(int n, int p, int expected)
{
    testequal(DigPow::digPow(n, p), expected);
}

Describe(digPow_Tests)
{
    It(Test)
    {
      dotest_normal(89, 1, 1);
      dotest_sequence_fail(123, 3, -1);
      dotest_big_number(46288, 3, 51);
    }
}; 
```

*   while문을 돌리며 vector 배열에 넣는다. 이후 for문으로 resum에 자리수에 제곱을 한 값을 넣는다.
*   이후에 if문으로 resum 값에 첫번째 인자의 값을 배수에 해당하는지 확인을 하고 해당하면 몇배수인지 아니면 -1을 리턴합니다.


## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
#include <cmath>
using namespace std;
class DigPow
{
public:
  static int digPow(int n, int p){
   long long sum=0;
   for(char digit : to_string(n)){
     sum+=pow(digit-'0',p++);
   }
   return (sum/n)*n==sum ? sum/n : -1;
  }
};
```

*   n을 string으로 변환하여 for문을 돌리는데 digit-'0'으로 int로 인식할 수 있도록 하였다.
*   return에서 ? 연산자를 사용하여 원하는 값을 리턴하였다.

## 배운 점

*   문제를 푸는데 몇자리 수 인지를 넣는 방법에대해 배열을 생각하였는데 Best Practice를 보고 간단하게 푸는법을 새로 알게되었다.

## 반성할 점

*   위의 방법을 생각하였지만 다시 변환해주는 것이 생각했던 것과 비슷할 것 같아서 안했는데 다른 사람의 풀이를 보니 훨씬 간단하다.

## Action Items

*   필요한대로 변환할 수 있는 능력을 기르자!