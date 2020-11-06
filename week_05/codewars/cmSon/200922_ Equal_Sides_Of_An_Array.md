# Tribonacci Sequence

## 문제 설명

*  인덱스 N을 기준으로 양옆의 합이 같은 인덱스 N을 찾아라.

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <vector>
using namespace std;

int find_even_index (const vector <int> numbers) {
  int total_sum = 0;
  int right_sum = 0;
  int left_sum = 0;
  
  for(auto num : numbers) total_sum += num;

  for(int i = 0; i < numbers.size(); i++){
    
    right_sum = total_sum - left_sum - numbers[i];
    
    if(left_sum == right_sum) return i;
    else left_sum += numbers[i];
  }
  
  return -1;
}
```

*  먼저 배열에있는 숫자의 총합을 구한다음,
*  for 문을 돌리면서 index의 오른쪽과 왼족의 합을 구해주어 같은지 판단하였다. 같으면 해당 인덱스를 반환해주었고 다른 경우 인덱스에 해당 값을 left_sum에 더해 다음 인덱스에서 판단할떼 사용하도록 하였다.
*  그리고 만약 for문을 빠져나가면 index가 존재하지 않는 거니 -1을 리턴하게 해주었다.
*  합을 구할때 right_sum은 total_sum에서 left_sum과 해당 인덱스 빼주었고, 그 다음 left_sum과 같은지 판단하여 주었다.

### 테스트 코드
```c++
#include <vector>
using namespace std;

Describe (ShouldPassAllTheTestsProvided)
{
    It (test_find_even_index_when_result_is_exits)
    {
      {
        vector <int> numbers { 1,2,3,4,3,2,1 };
        int expected = 3;
        Assert::That(find_even_index (numbers), Equals(expected));
      }
      
      {
        vector <int> numbers { 1,100,50,-51,1,1 };
        int expected = 1;
        Assert::That(find_even_index (numbers), Equals(expected));
      }
       
      {
        vector <int> numbers { 20,10,30,10,10,15,35 };
        int expected = 3;
        Assert::That(find_even_index (numbers), Equals(expected));
      }   
      
      {
        vector <int> numbers { -1,-2,-3,-4,-3,-2,-1 };
        int expected = 3;
        Assert::That(find_even_index (numbers), Equals(expected));
      }
      
      {
        vector <int> numbers { 10,-80,10,10,15,35,20 };
        int expected = 6;
        Assert::That(find_even_index (numbers), Equals(expected));
      }
    }
  
    It (test_find_even_index_when_result_is_not_exits)
    {
      vector <int> numbers { 1,2,3,4,5,6 };
      int expected = -1;
      Assert::That(find_even_index (numbers), Equals(expected));
    }
  
    It (test_find_even_index_when_result_is_0)
    {
      {
        vector <int> numbers { 0,0,0,0,0 };
        int expected = 0;
        Assert::That(find_even_index (numbers), Equals(expected));
      }
      {
        vector <int> numbers { 20,10,-80,10,10,15,35 };
        int expected = 0;
        Assert::That(find_even_index (numbers), Equals(expected));
      }
    }
    
};

```

*  테스트 코드 -1과 0을 리턴할때는 따로 구분해주었고, 나머지 일반적인 경우를 작성하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <vector>
#include <numeric>
using namespace std;

int find_even_index (const vector <int> numbers) {
  for (int index = 0; index < numbers.size(); index++)
  {
    int left_sum = std::accumulate(numbers.begin(), numbers.begin() + index, 0);
    int right_sum = std::accumulate(numbers.begin() + index + 1, numbers.end(), 0);
    if (left_sum == right_sum)
      return index;
  }
  return -1;
}
```

### Clever

```c++
#include <vector>
#include <numeric>
using namespace std;

int find_even_index (const vector <int> numbers) {
  for (int index = 0; index < numbers.size(); index++)
  {
    int left_sum = std::accumulate(numbers.begin(), numbers.begin() + index, 0);
    int right_sum = std::accumulate(numbers.begin() + index + 1, numbers.end(), 0);
    if (left_sum == right_sum)
      return index;
  }
  return -1;
}
```

*  numeric 헤더에 있는 accumulate 함수를 이용하여 인덱스을 기준으로 양옆의 합을 구했으며, 이를 이용해 합이 같은지 판단하였다.

### Other

```c++
#include <vector>
using namespace std;

int find_even_index (const vector <int> numbers) {
  int sum_all=0, sum_left=0, length=numbers.size();
  
  for (int i=0 ; i<length; i++)
    sum_all += numbers.at(i);
  for (int i=0 ; i<length; i++)
  {
    if ( (2*sum_left) == sum_all-numbers.at(i) ) return i;
    sum_left += numbers.at(i);
  } 
  return -1;
}
```
*  이런 방법을 쓰면 변수를 줄일수 있구라고 신기해서 가져왔다.

## 배운 점

*  예전에 accumulate 함수에 대해 알게되었는데 이번에 생각이 났음에도 무슨차이가 있을까 하고 사용하지 않았다. 
*  하지만 이번 문제를 통해 accumulate함수가 매우 유용하게 느껴졌으며 for문을 적는 수고를 덜어주는거 같아 자주 사용해야겠다.

## Action Item

*  최대한 다양한 헤더와 함수를 이용하면서 익숙해지도록 하자!