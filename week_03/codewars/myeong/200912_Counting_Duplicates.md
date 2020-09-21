# Counting Duplicates

## 문제 설명

*   중복되는 알파벳의 갯수를 출력한다. ( 단 중복되는 알파벳의 소문자 대문자를 통일하여 생각한다. )

## 나의 풀이 방법

```cpp
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{
  int standard=0;
  string copy_in=in;
  int compare=0;
  int com_count;
  int recount=0;
    
  while(in[standard]!='\0') {
  com_count=0;
  compare=0;
    while(copy_in[compare]!='\0') {
      if(tolower(in[standard])==tolower(copy_in[compare])) { 
        com_count++; 
        copy_in.erase(copy_in.begin()+compare);
        compare--;
      }
      compare++;
      }

    if(com_count>=2) { recount++; }
    standard++;
  }

  return recount;
}


Describe(sample_Tests)
{
    It(small_Tests)
    {
        Assert::That(duplicateCount_blanck(" "), Equals(0));
        Assert::That(duplicateCount_null(""), Equals(0));
        Assert::That(duplicateCount_normal("aabbccde"), Equals(3));
        Assert::That(duplicateCount_lower_upper("aAbBcCdDe"), Equals(4));
        Assert::That(duplicateCount_not_sequence("acbABCDEcde"), Equals(5));
        Assert::That(duplicateCount_random("abcdefasdefasdasde"), Equals(5));
    }
};
```

*   while문을 2중으로한다. 첫번째 while문은 기준이될 것이고 두번째 while문은 비교를 할 것이다. 
    이에 필요한 변수 compare, standard, copy_in을 지정하고 기준인 in을 넣어 비교용으로 사용한다.
*   비교하는 while문 안에서 기준과 비교가 같은지 확인할 것인데 대문자인지 소문자인지 모르므고 둘다 소문자로하여 비교한다.
*   if문 안에서 비교한 한 문자열을 삭제해준다. 한칸씩 밀렸을 경우를 예상해 compare--;를 한다. 
*   마지막 if문으로 중복된 것을 2개 이상이면 recount++을 하여 체크한다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
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

*   대문자 소문자로 이루어져있어 번거로우므로 for문에서 다 소문자로 바꿔준다.
*   return을 할때 처음부터끝까지 체크하며 count.second가 1이 넘는 것들로 return을 하므로 중복된 것이 나오게 된다.

## 배운 점

*   unordered_map이라는 헤더를 처음 알게되었다.

## 반성할 점
*   2중 while문을 사용하는 방법 외에 다른 방법으로 문제를 풀어보고 싶다.

## Action Item

*   문제는 미리미리!!