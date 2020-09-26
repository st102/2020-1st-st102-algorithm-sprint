# Are they the "same"?

## 문제 설명

*  두 개의 배열이 주어진다. 두 개의 배열이 같은지 판단하라.
*  이때 같음의 기준의 첫 번째 배열의 각 원소의 제곱 값이 두 번째 배열에 존재해야한다.

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <vector>
#include <algorithm>

using namespace std;
class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
      for(int i = 0; i < a.size(); i++)
        a[i] *= a[i];
  
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      
      return a == b;
    }
};
```

*  첫 번째 배열의 각 원소를 제곱한후 두 배열을 정렬하여 첫 번째 배열과 두 번째 배열을 비교하였다.

### 테스트 코드
```c++
#include <vector>

void dotest(std::vector<int> a, std::vector<int> b, bool sol)
{
    bool ans = Same::comp(a, b);
    Assert::That(ans, Equals(sol));
}

Describe(Comp_Tests)
{
    std::vector<int> a;
    std::vector<int> b;
  
    It(tests_comp_when_result_true)
    {
        a = {121, 144, 19, 161, 19, 144, 19, 11};
        b = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
        dotest(a, b, true);
       
        
    }  
    It(tests_comp_when_result_false)
    {
      a = {121, 144, 19, 161, 19, 144, 19, 11};
      b = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
      dotest(a, b, false);
    }
    It(test_code_when_array_is_null){
        a = {};
        b = {};
        dotest(a, b, true);
      
        a = {1,2,3,4};
        b = {};
        dotest(a, b, false);
    }
};
```
*  테스트 코드는 true를 반환할 때 false를 반환할때 null 배열을 넘겨줄떄로 나누었다.



## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <algorithm>

class Same {
public:
  static bool comp(std::vector<int>, std::vector<int>);
};

bool Same::comp(std::vector<int> a, std::vector<int> b) {
  for (auto& v : a) {
    v = v * v;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return a == b;
}
```

### Clever

```c++
#include <algorithm>

class Same {
public:
  static bool comp(std::vector<int>, std::vector<int>);
};

bool Same::comp(std::vector<int> a, std::vector<int> b) {
  for (auto& v : a) {
    v = v * v;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return a == b;
}
```

*  나랑 같은 코드이다.

## 아쉬운 점

*  처음 코드를 작성하였을 때 테스트 코드를 통과해도 codewars 테스트 코드를 통과하지 못하였다.
*  아마 음수를 생각해주지 않아서 통과하지 못한거 같다. sort 부분을 for문이후로 옮겨줌으로서 해결하였다.
*  테스트를 코드를 조금더 신경써서 작성해야 할거 같다.

## Acition Item

*  테스트 코드의 case를 조금 더 신경써서 나누자!