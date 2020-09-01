# Vowel Count

## 문제 설명

*   문자열에서 모음을 빼서 출력하기

## 나의 풀이 방법

```cpp
# include <string>

std::string disemvowel(std::string str)
{
    int i=0;
  
    while(str[i]!='\0') {
      if( str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
         str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' ) {
        str.erase(i,1);
        i--;
      }
      i++;
    }
    return str;
}
```

*   while문으로 문자열의 끝에서 끝나도록 하였으며 if문을 사용하여 모음 문자들을 찾아 제거하였다.
*   제거하면 문자가 하나씩 밀려난다고 생각되어 i--를 추가하여 모든 문자를 검사할 수 있도록 했다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
# include <string>
# include <regex>
std::string disemvowel(std::string str)
{
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}
```

*   Best Pactice와 Clever이 같은건 하면서 처음본다. regex라는 헤더를 사용하여 모음문자를 제거하였다.

## 배운 점

*   다른 사람의 풀이를 보며 regex라는 헤더가 무엇인지를 찾아보고 알게되었다.

## 반성할 점

*   아직은 모르는게 많아 짧게 푸는 것보다 정확하게 문제를 푸는 것에 집중해야겠다.

## Action Item

*   반성할점과 같이 문제를 정확하게 풀자!!