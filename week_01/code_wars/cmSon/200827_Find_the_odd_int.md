# Find the odd int 

## 문제 설명

*  vector 안에 홀수번 존재하는 값을 찾아라.
*  항상 홀수번 존재하는 값이 존재한다.

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include <vector>

int findOdd(const std::vector<int>& numbers) {

  for (int i : numbers) {
    if (count(numbers.begin(), numbers.end(), i) % 2 != 0)
    {
      return i;
    }
  }
}

```
*  for문을 이용하여 벡터안의 인자에 접근한후 count 함수를 이용하여 해당 숫자가 홀수번 나올경우 해당 숫자를 return한다.

### 테스트 코드
```c++
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

*  나랑 비슷하지만 모든 경로에서 return을 해주었다. 또한 auto라는 키워드를 이용하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
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

*  나랑 비슷하지만 모든 경로에서 return을 해주었다. 또한 auto라는 키워드를 이용하였다.

### Clever

```c++
#include <functional>
#include <numeric>
#include <vector>

int findOdd(const std::vector<int>& numbers) {
  return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}
```

*  첨보는 함수가 나와 당황스러웠다...
*  찾아보나 알고리즘 문제에 유용하게 사용되는 함수라한다.
*  하지만 아무리 문서를 읽어도 이해가 되지 않았다 더 공부해야겠다 ㅠㅠ

## 배운 점

*  const형의 vector는 반복자인 being이나 end를 이용할수 없고 cbeing, cend를 이용해야한다는 점을 첨 알게되었다.
*  count 함수를 이용하면 편하게 특정 값의 개수를 알수 있다는 점을 알게되었다.

## 반성할 점

*  vector를 한번 공부했었는데 이번에 사용할때 아무것도 기억이 나지 않았다. 공부는 확실히 해야한다!
*  많은 코드를 보니 모든 경로에서 return 값을 작성해주는거 같다.

## Action Item

*  vector를 제대로 거의 처음 사용한거 같다. 부족한 부분이 많아 거의 처음부터 공부한거 같다.
*  어쩡쩡하게 알고 있는 부분을 이번 기회에 확실히 잡고 넘어 가야할거 같다.