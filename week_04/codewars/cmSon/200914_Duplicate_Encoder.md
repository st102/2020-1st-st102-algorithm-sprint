# Duplicate Encoder

## 문제 설명

*  주어진 문자열에서 2번 이상 나오는 문자는 ")"로 1번만 나오는 문자는 "("로 변환하여 새로운 문자열을 만들어라

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include <string>
#include <map>

using namespace std;

string duplicate_encoder(const string& word){
  map<char,int> character_count;
  string result = "";
  
  for(auto character : word)
    character_count[tolower(character)]++;
  
  for(auto character : word)
    result += (character_count[tolower(character)] > 1)? ")" : "(";
  
  
  return result;
}
```
*  저번에 알게된 map 자료형을 통해서 문자열에 포함된 문자의 반복횟수를 세주었고.
*  이를 통해 중복 문자 여부를 판단하여 ")" 와 "("에 대한 문자열을 작성하였다.

### 테스트 코드
```c++
Describe(Tests)
{  
    It(test_code_when_all_character_appears_only_once_and_lower)
    {
        Assert::That(duplicate_encoder("din"), Equals("((("));
        Assert::That(duplicate_encoder("chamin"), Equals("(((((("));
    }
  
    It(test_code_when_all_character_appears_more_than_once_and_lower){
        Assert::That(duplicate_encoder("boob"), Equals("))))"));
        Assert::That(duplicate_encoder("opposs"), Equals("))))))"));
    }
  
    It(test_code_when_all_character_appears_more_than_once_and_upper){
      Assert::That(duplicate_encoder("DIN"), Equals("((("));
      Assert::That(duplicate_encoder("CHAMIN"), Equals("(((((("));
    }
  
    It(test_code_when_only_lower){
      Assert::That(duplicate_encoder("recede"), Equals("()()()"));     
      Assert::That(duplicate_encoder("success"), Equals(")())())"));
    }
  
    It(test_code_when_only_upper){
      Assert::That(duplicate_encoder("CODEWARRIOR"), Equals("()(((())())"));
      Assert::That(duplicate_encoder("RECEDE"), Equals("()()()"));     
    }
      
    It(test_code_composed_all_case){
      Assert::That(duplicate_encoder("Supralapsarian"), Equals(")()))()))))()("));
      Assert::That(duplicate_encoder("Codewarrior"), Equals("()(((())())"));
    }
        
    It(test_code_composed_specaial_case){
      Assert::That(duplicate_encoder("(( @"), Equals("))(("));
      Assert::That(duplicate_encoder(" ( ( )"), Equals(")))))("));
    }
};
```

*  각각 중복 문자 포함 여부와 대문자 소문자 여부에 따라 케이스를 나누었고, 특수문자에 대한 경우도 따로 나누어 주었다.

## 다른 사람의 풀이 방법

### Best Practice

```C++
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

### Clever

```c++
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

*  나랑 같은 코드이다.

## Action Item

*  맨 처음 코드를 작성하기전 test code를 작성하는 습관이 안되있다...