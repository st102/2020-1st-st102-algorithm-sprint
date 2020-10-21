# Playing with Digits

## 문제 설명

*  정수 n과 p가 주어진다. 주어진 n의 각자리수에 대해서 제일 큰 자리수부터 p제곱을 하여 p를 1씩 증가시켜가며 모든 자리수의 합을 구한다.
*  그 다음 구해진 합을 n으로 나누어 정수가 나오면 그 수를 리턴하고 아니면 -1을 리턴하여러

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <string>
#include <cmath>

using namespace std;

class DigPow
{
public:
  static int digPow(int n, int p);
};

int DigPow::digPow(int n, int p){
  string n_to_string = to_string(n);
  int digit_sum = 0;
  
  for(auto digit : n_to_string){
    digit_sum += pow(digit - '0', p++);
  }
  
  return (digit_sum % n == 0) ? digit_sum / n : -1;
}

```

*  cmath 헤더에 있는 sqrt 함수를 이용하여 제곱근을 구하였고, 이를 정수인지 아닌지 판단하였다.

### 테스트 코드
```c++
Describe(digPow_Tests)
{
    It(test_digPow_with_success)
    {
      Assert::That(DigPow::digPow(89, 1), Equals(1));
      Assert::That(DigPow::digPow(46288, 3), Equals(51));
      Assert::That(DigPow::digPow(114, 3), Equals(9));
    }
  
    It(test_digPow_with_fail)
    {
      Assert::That(DigPow::digPow(92, 1), Equals(-1));
    }
};  

//codewars test code
void testequal(int ans, int sol) {
    Assert::That(ans, Equals(sol));
}
void dotest(int n, int p, int expected)
{
    testequal(DigPow::digPow(n, p), expected);
}
Describe(digPow_Tests)
{
    It(test)
    {
      testequal(89,1,1);
    }
  
};  
```

*  성공할 경우와 아닌 경우로 나누어 테스트 코드를 작성하였습니다.
*  주석아래있는 코드는 codewars에 작성되어있던 testcode를 도와주는 함수인데. 이런식으로 함수를 만들면 testcode가 조금더 보기 편해지는 거 같다.



## 다른 사람의 풀이 방법

### Best Practice

```c++
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

### Clever

```c++
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

*  string cast한 변수를 따로 지정해주지 않았다는 점과 마지막 return할때 조건 부분이 다르다.

## 아쉬운 점

*  string으로 cast한 부분은 한번만 사용해서 따로 변수를 지정할 필요가 없는데 리펙토링 할떄 발견하지 못해 아쉽다.

## Action Item

*  테스트 코드르 작성할때 함수를 만들어 보기 편하게 하는것도 좋은 방법인거 같다.
