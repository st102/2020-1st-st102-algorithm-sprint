# Highest and lowest

## 문제 설명

*  공백으로 구분된 숫자의 나열로 이루어진 문자열에서 최대값과 최소값을 구하여라.

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <string>
#include <cstring>

using namespace std;

string highAndLow(const string& numbers){
  char * char_numbers = (char *)numbers.c_str();
  char * number = strtok(char_numbers," ");
  int highest = atoi(number);
  int lowest = atoi(number);
  
  while(number != NULL){
    int number_to_integer = atoi(number);
    
    highest = (highest < number_to_integer)? number_to_integer : highest;
    lowest = (lowest > number_to_integer)? number_to_integer : lowest;
    
    number = strtok(NULL, " ");
  }
  
  return to_string(highest) + " " + to_string(lowest);
}
```

*  주어진 문자열을 char형으로 변환하여 strtok함수를 이용하여 공백을 구분하였다. 
*  문자열에서 맨 처음에 나오는 숫자를 기준으로 while문에서 highest 와 lowest를 찾아주었다.

## 테스트 코드

```c++
Describe(HighAndLow){
  It(test_code_basic_numbers){
    Assert::That(highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4"), Equals("42 -9"));
  }
  
  It(test_code_sort_numbers){
    Assert::That(highAndLow("-10 -7 -3 1 3 5 7"), Equals("7 -10"));
  }
  
  It(test_code_single_number){
    Assert::That(highAndLow("50"), Equals("50 50"));
  }
  
  It(test_code_only_plus_numbers){
    Assert::That(highAndLow("8 3 10 9 89"), Equals("89 3"));
  }
  
   It(test_code_only_minus_numbers){
    Assert::That(highAndLow("-8 -100 -91 -78 -5"), Equals("-5 -100"));
  }
  
   It(test_code_only_plus_and_zero_numbers){
    Assert::That(highAndLow("8 3 10 9 89 0"), Equals("89 0"));
  }
  
  It(test_code_only_minus_and_zero_numbers){
    Assert::That(highAndLow("-8 -100 -91 -78 -5 0"), Equals("0 -100"));
  }
  
  It(test_code_only_minus_and_minus_numbers){
    Assert::That(highAndLow("-8 9 -12 10 -91 15 -78 99 -5"), Equals("99 -91"));
  }
};
```
*  음수, 양수, 0을 통해 나올수 있는 숫자 조합들에 대하여 테스트 코드를 작성하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <string>
#include <sstream>
#include <limits>

std::string highAndLow(const std::string& numbers){
  std::stringstream ss(numbers);
  int temp, min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
  while (ss >> temp) {
    min = (temp < min) ? temp : min;
    max = (temp > max) ? temp : max;
  };
  return std::to_string(max) + " " + std::to_string(min);
}
```

### Clever

```c++
#include <string>
#include <sstream>
#include <limits>

std::string highAndLow(const std::string& numbers){
  std::stringstream ss(numbers);
  int temp, min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
  while (ss >> temp) {
    min = (temp < min) ? temp : min;
    max = (temp > max) ? temp : max;
  };
  return std::to_string(max) + " " + std::to_string(min);
}
```

*  정말 c++ 다운 코드인거 같다. stringstream과 >> 를 이용하여 >> operator는 공백을 기준으로 받아온다는 것을 이용하여 공백을 구분해주었다.
*  그리고 while문에 조건에 ss >> temp는 string의 마지막은 null로 끝난다는 것을 잘 이용해준거 같다.
*  max, min 함수는 왜 사용한지 잘 모르고 찾아봐도 잘 모르겠다...
*  하지만 맨처음 변수 선언에서 , 를 이용하여 선언하는 것은 변수가 한눈에 안들어와 별로 인거 같다.

## 배운 점 

*  stream과 >> operator를 이용하여 공백을 구분할수 있다는 점을 첨 알게 되었다. 앞으로 자주 써먹을 거 같다.

## 반성할 점
 
*  strtok는 특정 문자를 NULL 문자로 변환해주는 함수기 때문에 계속 strtok함수를 호출해야하는 번거로움이있다.
*  이떄문에 내코드는 c++ 스타일이 아닌 c 스타일의 코드인거 같은 느낌을 많이 받았다.
*  c에서 사용하는 함수에 대해서 c++ 스타일로 바꾸어 사용할수 있는걸 많이 고민하고 코드를 작성해야 할거 같다.

## Action Item

*  c언어를 맨처음 사용하며 c언어 함수에 익숙하지만 이를 c++ 스럽게 사용할수 있는 방법을 강구하자!