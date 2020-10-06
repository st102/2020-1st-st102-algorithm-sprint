#  Number of People in the Bus

## 문제 설명

*   각 정수배열에는 버스 탑승 인원수(첫 번째 항목)와 버스정류장 내 하차 인원수(두 번째 항목)를 나타내는 두 가지 항목이 있다.
    마지막 버스 정류장(마지막 배열차 이후) 후에도 버스에 남아 있는 사람의 수를 반환하라.

## 나의 풀이 방법
```cpp
#include <utility>
#include <vector>

using namespace std;
unsigned int number(const std::vector<std::pair<int, int>>& busStops){
  int people=0;
  int busstops=0;
  
  for(int i=0; i<busStops.size(); i++) {
    busstops+=busStops[i].first;
    people+=busStops[i].second;
  }
  if(busstops-people>0) {
    return busstops-people;
  } else return 0;
}

using V = std::pair<int, int>;
using V2 = std::vector<V>;

Describe(Number){
  It(BasicTests){
    Assert::That(number_empty(V2{V{10,0},V{13,0},V{17,40}}), Equals(0));
    Assert::That(number_zero(V2{V{0,0}}), Equals(0));
    Assert::That(number_normal(V2{V{10,0},V{3,5},V{5,8}}), Equals(5));
    Assert::That(number_big_number(V2{V{3,0},V{9,1},V{4,10},V{12,2},V{6,1},V{7,10}}), Equals(17));
  }
};
```

*   busstops와 people 변수들을 지정하고 각 배열의 first,second의 총합을 for문을 돌리며 저장한다.
*   if문을 사용하여 busstops-people로 버스에 남아있는 사람의 수를 반환하였다.

## 다른 사람의 풀이 방법

### Best Practice

```cpp
#include<vector>

unsigned int number(const std::vector<std::pair<int, int>>& busStops){
  int passengers = 0;
  for(auto i: busStops)  passengers += i.first - i.second;
  return passengers;
}
```

*   따로 구분없이 first와 second를 for문을 돌려 총합을 구하고 이를 바로 출력하였다.

### Clever

```cpp
#include<vector>
#include <numeric>

unsigned int number(const std::vector<std::pair<int, int>>& busStops){
  return std::accumulate(busStops.begin(), busStops.end(), 0, [](unsigned int sum, auto i) { return sum + i.first - i.second; });
}
```

*   numeric해더를 적용하여 accumulate를 사용하여 원하는 값을 바로 반환하도록 풀이하였다.

## 배운 점

*   numeric 헤더에 대해 accmulate를 사용하는 방법을 알게되었다.

## 반성할 점

*   코드를 제출하고 기억난 것이 문제에서 무조건 0이상이라고하여 굳이 if문이 필요없을 것 같다는 생각을 하였다.

## Action Items

*   문제를 제대로 이해하고 풀이를 하자!