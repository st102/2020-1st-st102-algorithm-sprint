# Take a Ten Minute Walk

## 문제 설명

*   10개의 문자가 주어졌을 때 문자열대로 이동하고 이를 원점으로 오면 true를 반환하여라.

## 나의 풀이 방법

```cpp
#include<vector>

bool isValidWalk(std::vector<char> walk) {
  int x=0;
  int y=0;
  int size=walk.size();
  if(size==10) {
    for(int index=0; index<size; index++) {
      if(walk[index]=='n') { y++; }
      else if(walk[index]=='s') { y--; }
      else if(walk[index]=='w') { x++; }
      else if(walk[index]=='e') { x--; }
      }
    if(x==0 && y==0) {
      return true;
    }
  }
  return false;
}

Describe(IsValidWalk)
{
    It(Test)
    {
        Assert::That(isValidWalk_normal(V{'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's'}), Equals(true));
        Assert::That(isValidWalk_ten_low(V{'n','s','n','s'}), Equals(false));
        Assert::That(isValidWalk_ten_high(V{'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'}), Equals(false));
        Assert::That(isValidWalk_normal_fail(V{'n','s','n','s','n','s','n','s','n','w'}), Equals(false));
    }
};

```

*   좌표를 생각했을때 원점 즉 0,0으로 온다면 된다고 생각하였다. x좌표 w,e y좌표 n,s를 위해 변수들을 지정하였다.
*   문제에서 10명일때만 판단한다고 했으므로 for문을 돌릴지 if문으로 판단하였다. 이후 돌리면서 if문으로 만났을 때 각각 수를 더하고  
    빼는 동작을 하며 이를 다 돈후에 0,0이 되었을 때 true를 출력하게 하였다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
#include<vector>
#include <algorithm> 

bool isValidWalk(std::vector<char> walk) {
  return walk.size() == 10 and 
         std::count(walk.begin(), walk.end(), 'e') == std::count(walk.begin(), walk.end(), 'w') and
         std::count(walk.begin(), walk.end(), 'n') == std::count(walk.begin(), walk.end(), 's');
}
```

*   count로 e,w n,s 각각의 개수가 동일할때 true를 출력하도록 하였다.

## 배운 점

*   count라는 함수가 유용하다는 것을 알게 되었다. 이를 배워서 실전에 사용해볼 것이다.

## 반성할 점
*   count라는 함수를 전에 문제에서도 봤으나 주의깊게 보지 않은 점이 아쉽다. 잘 봤다면 이번 문제에서 활용해볼 수도 있었을 것이다.

## Action Item

*   count를 정복하자!!