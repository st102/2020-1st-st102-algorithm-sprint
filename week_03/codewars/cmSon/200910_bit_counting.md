# Highest and lowest

## 문제 설명

*  주어진 숫자를 2진수로 표현하여 1의 갯수를 구하여라

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#define BINARY 2

unsigned int countBits(unsigned long long n){
  
  int bit_count = 0;
  
  while(n){
    bit_count += n % BINARY;
    n /= BINARY;
  }
  
  return bit_count;
}
```

*  10진수를 2진수로 변경하는 코드를 응용하였다. 
*  주어진 수를 2로 나눈 나머지를 

### 테스트 코드
```c++
Describe(CountBits){
    It(test_code_given_number_0){
        Assert::That(countBits(0), Equals(0));
    }
    It(test_code_when_number_is_smaller){
        Assert::That(countBits(4), Equals(1));
        Assert::That(countBits(7), Equals(3));
        Assert::That(countBits(9), Equals(2));
        Assert::That(countBits(10), Equals(2));
        Assert::That(countBits(26), Equals(3));
    }
    It(test_code_when_number_is_bigger){
        Assert::That(countBits(3811), Equals(8));
        Assert::That(countBits(77231418), Equals(14));
        Assert::That(countBits(12525589), Equals(11));
        Assert::That(countBits(392902058), Equals(17));
    }
  
};
```

*  조건이 input값이 0이상이라고 주어져 있어 0이상의 값들에 대해서 0일때 작은수 일때 큰수 일때로 나누어 작성하였습니다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <limits>
#include <bitset>
inline constexpr unsigned int countBits(const unsigned long long n) noexcept {
  std::bitset<std::numeric_limits<unsigned long long>::digits> b(n);
  return b.count();
}
```
*  std::numeric_limits<T>::digits 를 이용하여 주어진 숫자의 자료형에 대한 기수(bit)의 자릿수를 구한다음
*  해당 자릿수 만큼은 bitset 타입을 지정하고 숫자 n에 대한 bitset 변수 n을 생성한다.
*  count 함수를 사용하여 1인 bit를 계산하였다.

### Clever

```c++
unsigned int countBits(unsigned long long n){
  return std::bitset<8 * sizeof(n)>(n).count();
}
```

*  best pratice와 비슷한 코드이지만 여기서는 bitset를 numeric_limts를 사용하지 않고
*  해당 자료형의 byte형에 8를 곱하는 식으로 bit의 자릿수를 구하였다.\

## 배운점

*  bitset를 이용하여 쉽게 bit 값을 계산할수 있다는것을 알게되었다.
*  참고 자료 : https://www.crocus.co.kr/549

## 아쉬운 점

*  codewars에서 보면 random 값에 대한 test도 진행하는 걸 볼수 있는데 나도 다음에는 random값에 대한 testcode를 한번 작성해봐야겠다.

## Action Item

*  c++에는 유용한 헤더들이 많은거 같다. 일일이 찾기는 어렵지만 이렇게 문제를 풀며 하나씩 알아가자!