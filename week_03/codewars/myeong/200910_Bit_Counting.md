# Bit Counting

## 문제 설명

*   10진수를 2진수로 변환할 때 1의 개수를 카운트하여라.

## 나의 풀이 방법

```cpp
unsigned int countBits(unsigned long long n){
  unsigned long long mok=-1;
  unsigned long long remind;
  int recount=0;
  while(mok!=0) {
    mok=n/2;
    remind=n-mok*2;
    if (remind==1) { recount++; }
    n=mok;
  }
  return recount;
}

Describe(CountBits){
  It(Tests){
    Assert::CountBits_zero(countBits(0), Equals(0));
    Assert::CountBits_even(countBits(2), Equals(1));
    Assert::CountBits_odd(countBits(3), Equals(2));
    Assert::CountBits_ten_over_even(countBits(124568), Equals(9));
    Assert::CountBits_ten_over_odd(countBits(528657), Equals(5));
  }
```

*   몫을 해당하는 변수 mok 나머지를 해당하는 변수 remind를 지정하여 while문에서 2진수에서 1이 나올 때 
    count를 하였다. 

## 다른 사람의 풀이 방법

### Best Practice

```cpp
#include <limits>
#include <bitset>
inline constexpr unsigned int countBits(const unsigned long long n) noexcept {
  std::bitset<std::numeric_limits<unsigned long long>::digits> b(n);
  return b.count();
}
```

*   limits헤더와 bitset헤더를 사용하여 문제를 해결하였다.

### Clever
```cpp
unsigned int countBits(unsigned long long n){
  int count = 0;
  while (n) {
    n &= (n-1);
    ++count;
  }
  return count;
}
```

*   비트 단위 연산자를 사용하여 while문으로 1을 지우면서 count를 센 후 이를 출력한다.

## 배운 점

*   bitset과 limits 헤더에 대해 알게 되었다.

## 반성할 점
*   비트 단위 연산자를 자주 사용하지 않다보니 이를 쓰는걸 잊었다.

## Action Item

*   bitset, limits 헤더를 이해하자!!