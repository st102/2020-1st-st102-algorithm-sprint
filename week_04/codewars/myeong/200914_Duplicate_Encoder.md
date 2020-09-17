# Duplicate Encoder

## 문제 설명

*   중복되는 문자열은 )로 아닌 것은 (로 출력한다. ( 단 중복되는 알파벳의 소문자 대문자를 통일하여 생각한다. )

## 나의 풀이 방법

```cpp
#include <string>
#include <algorithm>
using namespace std;
std::string duplicate_encoder(const std::string& word) {
  string restr = word;
  string restr_last;
  int standard = 0;
  int compare = 0;
  int count = 0;
  int length = word.length();

  for (standard = 0; standard < length; standard++) {
    count = 0;
    for (compare = 0; compare < length; compare++) {
      if (tolower(restr[standard]) == tolower(restr[compare])) {
        count++;
      }
    }
    if (count >= 2) {
      restr_last += ")";
    }
    else restr_last += "(";
  }
  return restr_last;
}

Describe(Tests)
{  
    It(Basic_Tests)
    {
        Assert::That(duplicate_encoder_normal("myeong"), Equals("(((((("));
        Assert::That(duplicate_encoder_multi("seongmyeonggeun"), Equals("())))(())))))()"));
        Assert::That(duplicate_encoder_upper_lower("SeongMyeongGeun"), Equals("())))(())))))()"));
        Assert::That(duplicate_encoder_not_literal("Seong-Myeong-Geun"), Equals("()))))(()))))))()"));
    }
};
```

*   while문을 2중으로한다. 첫번째 while문은 기준이될 것이고 두번째 while문은 비교를 할 것이다. 
    이에 필요한 변수 compare, standard, restr, restr_last로 지정하고 기준인 in을 넣어 비교용으로 사용한다.
*   비교하는 while문 안에서 기준과 비교가 같은지 확인할 것인데 대문자인지 소문자인지 모르므고 둘다 소문자로하여 비교한다.
*   count를 세고 이 문자열에서 2개이상이되면 문자열에서 )를 추가하며 한개면 (를 추가하여 원하는대록 출력한다.
## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
#include <string>
#include <cctype>

std::string duplicate_encoder(const std::string& word){

    std::map<char, int> table;
    for(auto x : word) table[std::tolower(x)]++;
    
    std::string result;
    for(auto x: word) result += (table[std::tolower(x)]==1)? "(":")";
    
    return result;
}
```

*   map을 활용하여 다 소문자로 변환하며 여기서 각 문자마다 몇개씩 있는가에 따라 result에 원하는 문자열을 대입한다.

## 배운 점

*   map이라는 함수를 활용해보는 것에 대해 배웠다.

## 반성할 점
*   map 함수를 알고 다음 문제부터는 적용을 해보고 싶다.

## Action Item

*   map을 정복해야겠군