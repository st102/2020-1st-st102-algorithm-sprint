# Take a Ten Minute Walk

## 문제 설명

*  한 블럭을 가는데 1분이 소요되는 마을이 있다.
*  무작위로 제공되는 방향 배열을 보고 다시 원위치로 돌아오는데 정확히 10분이 걸리는 배열 여부를 판단하여라.

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include<vector>

#define N 1
#define S -1
#define W 2
#define E -2

bool isValidWalk(std::vector<char> walk) {
  int return_home = 0;
  
  if(walk.size() != 10) return false;
    
  for (auto direction : walk) {
    return_home += (direction == 'n') ? N : 
                   (direction == 's')? S : 
                   (direction == 'w')? W : E;
  }
  
  return (return_home == 0);
}
```
*  먼저 주어진 배열의 크기가 10이 아니라면 10보다 적거나 많은 시간이 걸리는 거니 이를 먼저 판단하여주었고
*  n = 1, s = -1, w = 2, e = -2 라고 지정하여 배열의 모든 원소에 대한 값의 합이 0이 나오는가 여부를 판단해 주었다.

### 테스트 코드
```c++
using V = std::vector<char>;

Describe(IsValidWalk)
{
    It(test_code_given_true)
    {
      Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','s'}), Equals(true));
      Assert::That(isValidWalk(V{'e','w','e','w','n','s','n','s','e','w'}), Equals(true));
      Assert::That(isValidWalk(V{'n','s','e','w','n','s','e','w','n','s'}), Equals(true));
      Assert::That(isValidWalk(V{'s','e','w','n','n','s','e','w','n','s'}), Equals(true));
    }
  
    It(test_code_given_false)
    {
      Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','n'}), Equals(false));
      Assert::That(isValidWalk(V{'e','e','e','w','n','s','n','s','e','w'}), Equals(false));
      Assert::That(isValidWalk(V{'n'}), Equals(false));
      Assert::That(isValidWalk(V{'n','s'}), Equals(false));
      Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','s','n','s'}), Equals(false));
      Assert::That(isValidWalk(V{'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'}), Equals(false));
    }
};
```

*  간단하게 true가 나오는 경우 false가 나오는 경우로 나누었다.

## 다른 사람의 풀이 방법

### Best Practice

```C++
#include <vector>
#include <algorithm> 

bool isValidWalk(std::vector<char> walk) {
  return walk.size() == 10 and 
         std::count(walk.begin(), walk.end(), 'e') == std::count(walk.begin(), walk.end(), 'w') and
         std::count(walk.begin(), walk.end(), 'n') == std::count(walk.begin(), walk.end(), 's');
}
```

### Clever

```c++
#include <vector>
#include <algorithm> 

bool isValidWalk(std::vector<char> walk) {
  return walk.size() == 10 and 
         std::count(walk.begin(), walk.end(), 'e') == std::count(walk.begin(), walk.end(), 'w') and
         std::count(walk.begin(), walk.end(), 'n') == std::count(walk.begin(), walk.end(), 's');
}
```

*  count 함수를 이용하여 간단하게 작성한거 같다.

## Action Item

*  algorithm 해더의 함수 count를 이용해서 쉽게 풀이를 보면 굳이 배열의 처음부터 끝까지 탐색하는 반복을 한번더 해야하는가 라는 생각이 들었다.