# Highest and lowest

## 문제 설명

*  주어진 문자열에서 길이가 5이상인 단어를 뒤짚어 문장을 만들어라

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <regex>
#include <string>

using namespace std;

size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
  string copy_in = string(in);
	size_t result = 0;

	for (int i = 0; i < copy_in.length(); i++)
		copy_in[i] = ('A' <= copy_in[i] && copy_in[i] <= 'Z') ? tolower(copy_in[i]) : copy_in[i];


	while(!copy_in.empty()){
		char character = copy_in.front();
		regex regex_word({'[',character,']'});
		if (copy_in.find(character, 1) != string::npos) {
			result++;
		}
		copy_in = regex_replace(copy_in, regex_word, "");
	}
  
  return result;
}
```

*  먼저 char형을 편하게 사용하기 위해 string타입으로 새로운 copy_in 변수를 생성해주었다.
*  그 다음 문자열에 존재하는 대문자를 먼저 소문자로 변경해주었다. 
*  소문자 변환이 된 문자열을 가지고 맨 앞글자 문자가 find함수를 이용해 한번더 등장하는지 확인하고 한번더 등장하면 result 값을 1씩 증가 시켜주었다.
*  또한 한번 중복 검사를 거친 문자가 또다시 검사되는걸 방지하기 위해 regex 헤더를 이용해 해당 문자들을 문자열에서 제거해주는 과정을 거쳤다.

### 테스트 코드
```c++
Describe(sample_Tests)
{
    It(test_code_when_string_is_empty)
    {
      Assert::That(duplicateCount(""), Equals(0));
      Assert::That(duplicateCount(" "), Equals(0));
    }
  
    It(test_code_when_string_only_lower)
    {
      Assert::That(duplicateCount("aabbcde"), Equals(2));
      Assert::That(duplicateCount("coding"), Equals(0));
    }
  
    It(test_code_when_string_only_upper)
    {
      Assert::That(duplicateCount("ABBA"), Equals(2));
      Assert::That(duplicateCount("PORGRAMER"), Equals(1));
      Assert::That(duplicateCount("VARY"), Equals(0));
    }
    
    It(test_code_when_string_upper_and_lower)
    {
        
        Assert::That(duplicateCount("aabBcde"), Equals(2));
        Assert::That(duplicateCount("Indivisibility"), Equals(1));
        Assert::That(duplicateCount("Indivisibilities"), Equals(2));
    }   
};
```

*  빈 문자열인 경우, 소문자로만 이루어진 경우, 대문자로만 이루어진 경우, 둘다인 경우로 나누어 테스트 코드를 작성하였습니다.
*  문제 조건에서 문자를 제외한 숫자, 띄어쓰기는 문자열에 포함되지 않는다 하여 제외하였습니다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <string>
#include <unordered_map>
#include <algorithm>

#include <cctype>

std::size_t duplicateCount(const char* in) {
  std::unordered_map<char, unsigned> counts;
  for (const char* c = in; *c != '\0'; ++c) {
    ++counts[tolower(*c)];
  }
  return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
      return count.second > 1;
    });
}
```

### Clever

```c++
#include <string>
#include <unordered_map>
#include <algorithm>

#include <cctype>

std::size_t duplicateCount(const char* in) {
  std::unordered_map<char, unsigned> counts;
  for (const char* c = in; *c != '\0'; ++c) {
    ++counts[tolower(*c)];
  }
  return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
      return count.second > 1;
    });
}
```

*  mpa이라는 새로운 c++ STL이 등장하였다. map은 파이썬의 디렉토리 자료형과 유사한 구조인거 같았다. key와 value 값으로 이루어져있고. key 값에 따라 value값을 지정해줄수 있다. 
*  이 코드에서 for문을 통해 문자열 있는 모든 문자에 대해서 key값으로 지정하고 해당 key값에 대한 value 값을 1씩 증가시켜주는 방법을 통해 중복을 체크해준다.
*  그리고 algorithm 헤더에 있는 count_if에 함수를 이용하여 value 값이 1보다 큰 원소의 개수를 세주는 방식을 사용하였다.

## 배운 점

*  c++ 에는 파이썬처럼 디렉토리 자료형이 없을줄 알았는데 map 자료형이 있다는 것에 매우 놀라웠다. 
*  그리고 count_if, count 함수를 이용해 원소 개수를 쉽게 셀수 있다는 것도 알게되었다.

## 아쉬운 점

*  char형으로도 tolower 함수를 이용할수 있는걸 몰랐었다..
*  굳이 string 형으로 변환하지 않아도 char형으로 이용하는게 더 편할 수도 있게다라는 생각이 들었다.

## Action Item

*  ttd를 조금은 하는거 같다. 테스트 코드를 작성하고 일단 코드를 작성한뒤 코드를 조금씩 수정하는게 ttd가 맞는지모르겠다.