# Vowel Count

## 문제 설명

*   빈도수가 홀수인 정수를 찾기

## 나의 풀이 방법

```cpp
#include <vector>

using namespace std;

int findOdd(const std::vector<int>& numbers){
  int Odd_count=0;
  
  for(auto i : numbers) {
    Odd_count=0;
    for(auto j : numbers) {
      if(i==j) {
        Odd_count++;
      }
    }
    if(Odd_count%2==1) {
      return i;
    }
  }
}
```

*   for문을 두개 돌렸으며 홀수가 한번있다고 하였으므로 있는대로 각각의 정수에 해당하는 빈도수를 찾았다.
*   빈도수를 찾은 후에 이 정수의 빈도수가 짝홀 유무를 위해 if문으로 이를 찾았다.

## 다른 사람의 풀이 방법

### Best Practice

```cpp
#include <vector>

int findOdd(const std::vector<int>& numbers){
  for (auto elem: numbers){
    if (std::count(numbers.begin(), numbers.end(), elem) % 2 != 0) {
      return elem;
    }
  }
  return 0;
}
```

*   count라는 vector에서의 기능을 활용하여 for문 하나에 정수가 짝홀을 찾을 수 있도록 하였다.

###Clever

```cpp
#include <functional>
#include <numeric>
#include <vector>

int findOdd(const std::vector<int>& numbers) {
  return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}
```

*   functional헤더와 numeric헤더를 사용하여 문제를 풀었다. 코드 각각의 내용은 자세히는 잘모르겠습니다..

## 배운 점

*   언어는 풀 수 있는 방법은 많지만 아는만큼 간결해진다.

## 반성할 점

*   생소한 헤더가 많은데 이를 활용하지 못한점을 반성하고 싶다.

## Action Item

*   위와 비슷하지만 std에는 내가 모르는 기능들이 더 많은 것 같다. 이를 알고 나중에는 써보고싶다!!