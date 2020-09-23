# Find the next perfect square!

## 문제 설명

*   제곱이된 숫자가 주어지면 이 숫자의 다음 제곱을 찾아라. 단 제곱이 아닌 수가 들어오면 -1을 리턴한다.

## 나의 풀이 방법

```cpp
#include <cmath>
long int findNextSquare(long int sq) {
  if(floor(sqrt(sq))==ceil(sqrt(sq)))
    return pow(sqrt(sq)+1,2);
  return -1;
}

Describe(findNextSquareTests)
{
    It(BasicTests)
    {
        Assert::That(findNextSquare_normal(25), Equals(36));
        Assert::That(findNextSquare_normal_2(625), Equals(676));
        Assert::That(findNextSquare_big_number(319225), Equals(320356));
        Assert::That(findNextSquare_not_sqrt(123), Equals(-1));
        Assert::That(findNextSquare_minus(-25), Equals(-1));
    }
};
```

*   제곱인 수가 정수인가를 판단하는데 올림과 내림을 사용하였으며 이를 갔을때 return으로 제곱근에 1을 더하여 제곱을 리턴하였다.


## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
#include <cmath>    
long int findNextSquare(long int sq) {
  if(sqrt(sq) != (int)sqrt(sq)){return -1;}
  return  pow(sqrt(sq) + 1,2);
}
```

*   수의 제곱근을 구하고 이를 정수로 나타낸 것과 같지않으면 -1을 리턴하고 return으로 제곱근에 1을 더하고 제곱을 리턴하였다.

## 배운 점

*   floor, ceil 올림내림 헤더에서 있다는 것을 알게 되었다.

## Action Items

*   올림과 내림이 있는지는 몰랐으나 인터넷 검색을 통해 알게 되고 이를 활용했다는 점에서 뿌듯하다!