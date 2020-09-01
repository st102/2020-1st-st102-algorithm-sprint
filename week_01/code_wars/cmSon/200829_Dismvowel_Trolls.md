# Dismvowel Trolls

## 문제 설명

*  주어진 string에서 모음을 제거해라!

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include <iostream>
#include <string>

using namespace std;

string disemvowel(std::string str)
{
    string result_str = "";
 
    for (auto chr_in_str : str) {
        switch (chr_in_str) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            break;
        default:
            result_str.push_back(chr_in_str);
            break;
        }
    }

    return result_str;
}
```
*  주어진 문자열을 하나씩 확인해 switch문을 통해 모음 여부를 확인해 주었다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
# include <string>
# include <regex>
std::string disemvowel(std::string str)
{
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}
```

### Clever

```c++
# include <string>
# include <regex>
std::string disemvowel(std::string str)
{
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}
```
*  이번에는 best partice랑 clever의 풀이가 같았다.
*  둘다 정규식을 이용한 풀이이다.

### Others

```c++
# include <string>

std::string disemvowel(std::string str)
{
    for ( auto letter : "AEIOUaeiou" ) {
      str.erase(std::remove(str.begin(), str.end(), letter), str.end());
    }
    
    return str;
}
```

*  정규식에 익숙하지 않은 내가 떠올리수 있다고 생각하는 최선의 풀이이다.
*  주어진 문자열을 확인하는게 아닌 string의 erase함수를 이용하여 for문을 한번 돌때마다 각각에 해당되는 모음이 문자열에서 제거되게 하였다.

## 배운 점

*  c++에서 정규식 사용하는법을 첨 보았다. 빨리 정규식에 대해 익숙해져야할거같다
*  나는 주어진 문자열을 일일이 확인했는데 굳이 그럴 필요없이 모음에 대해서만 확인함으로서 코드가 확 준거를 알수있었다

## Action Item

*  처음으로 auto를 코드에 사용했다. 많은 solution코드를 봐도 auto를 자주 사용하는거 같다. 습관 들이자!.
*  정규식은 보면 볼수록 대단한거 같다. 빨리 공부해야지..