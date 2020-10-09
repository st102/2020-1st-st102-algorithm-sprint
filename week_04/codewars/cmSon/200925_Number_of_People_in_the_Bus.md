# Number of People in the Bus

## 문제 설명

*  첫번째에는 탑승한 승객 두번째에는 하차한 승객을 쌍으로 가진 배열을 통해 마지막 정류장에서 몇명의 승객이 버스에 남았는지 구하여라.

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <utility>
#include <vector>

using namespace std;

unsigned int number(const vector<pair<int, int>>& busStops){
  int last_people = 0;
  
  for(auto info : busStops)
    last_people += (info.first - info.second);
  
  return last_people;
}
```

*  for문을 통해 각각인자를 접근하여 계산하였다.

### 테스트 코드
```c++
using V = std::pair<int, int>;
using V2 = std::vector<V>;

Describe(Number){
  It(test_number_baisc){
    Assert::That(number(V2{V{10,0},V{3,5},V{5,8}}), Equals(5));
    Assert::That(number(V2{V{3,0},V{9,1},V{4,10},V{12,2},V{6,1},V{7,10}}), Equals(17));
    Assert::That(number(V2{V{3,0},V{9,1},V{4,8},V{12,2},V{6,1},V{7,8}}), Equals(21));
    Assert::That(number(V2{V{0,0}}), Equals(0));
    Assert::That(number(V2{V{10,0},V{13,0},V{17,40}}), Equals(0));
  }
};
```

## 다른 사람의 풀이 방법

### Best Practice

```c++
unsigned int number(const std::vector<std::pair<int, int>>& busStops){
  int passengers = 0;
  for(auto i: busStops)  passengers += i.first - i.second;
  return passengers;
}
```

### Clever

```c++
#include<vector>
#include <numeric>

unsigned int number(const std::vector<std::pair<int, int>>& busStops){
  return std::accumulate(busStops.begin(), busStops.end(), 0, [](unsigned int sum, auto i) { return sum + i.first - i.second; });
}
```

*  accumulate 함수에 람다식을 넘겨주여 계산을 편리하게 하였다.

## 배운 점

*  accumulate함수를 보며 맨 마지막 변수가 뭔지 잘 몰랐는데, 이제와서 보니 람다식이었다.
*  c++에서도 람다식이 존재한다는걸 첨알게 되었다. 자주 사용해야겠다.
*  또한 c++에서도 tuple과 pair이 존재하여 쌍으로 이루어진 데이터를 다룰수 있는걸 알게되었다.