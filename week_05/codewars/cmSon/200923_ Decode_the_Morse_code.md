# Tribonacci Sequence

## 문제 설명

*  주어진 모스코드를 해독하여라. 각각의 모스코드는 띄어쓰기로 구분하여 제공된다.
*  맨 앞과 뒤의 띄어쓰기는 의미가 없다.

## 나의 풀이 방법

### 문제 풀이 코드

```c++
using namespace std;

string decodeMorse(string morseCode) {
    
    string divided_blank = "";
    string decoded = "";
  
    for(auto token : morseCode){  
        if(token == ' ')
        {          
          if(divided_blank != "")
          {
            decoded += MORSE_CODE[divided_blank];
            divided_blank = "";
          }
          else if(!decoded.empty())
          {
            divided_blank = " ";
            decoded += divided_blank;
          }
        }
        else
        {
          divided_blank += token;
        }
    }
  
    decoded += MORSE_CODE[divided_blank];
  
    while(decoded.back() == ' '){
      decoded.pop_back();
    }
  
    return decoded;
}
```

*  띄어쓰기를 기준으로 주어진 문자열을 구분하였다. 
*  띄어쓰기를 만나기 전까지 divided_blank 변수에 모스코드를 저장하고 공백을 만나면 저장된 모스코드를 글자로 해독하여 decode변수에 이어붙였다.
*  만약 띄어쓰기가 연속으로 나올경우 decode가 빈문자열인지 아닌지 구분을 하여 빈문자열일 경우 맨 처음 나오는 공백이니 무시하도록 하였고 아닌 경우 decode에 띄어쓰기를 붙여주었다.
*  그 후 dicided_blank를 공백으로 지정하여 공백 다음 또 나오게 되는 공백을 무시하여주었다.
*  마지막으로 맨 마지막에 존재하는 공백들을 while문을 통해 제거해주었다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <regex>

const std::regex morse("([^\\s]+|\\s{3})");

std::string decodeMorse(std::string morseCode) {
  std::string decoded;
  
  auto begin = morseCode.begin() + morseCode.find_first_not_of(' ');
  auto end = morseCode.begin() + morseCode.find_last_not_of(' ') + 1;
  
  for (auto it = std::sregex_iterator(begin, end, morse); it != std::sregex_iterator(); ++it) {
    std::string str = it->str();
    decoded += str == "   " ? " " : MORSE_CODE[str];
  }
  
  return decoded;
}
```

### Clever

```c++
#include <regex>

const std::regex morse("([^\\s]+|\\s{3})");

std::string decodeMorse(std::string morseCode) {
  std::string decoded;
  
  auto begin = morseCode.begin() + morseCode.find_first_not_of(' ');
  auto end = morseCode.begin() + morseCode.find_last_not_of(' ') + 1;
  
  for (auto it = std::sregex_iterator(begin, end, morse); it != std::sregex_iterator(); ++it) {
    std::string str = it->str();
    decoded += str == "   " ? " " : MORSE_CODE[str];
  }
  
  return decoded;
}
```

*  정규식을 이용하였다.
*  srgex 함수를 이용하여 해당 문자열에서 정규식에서 부합하는 부분만 재귀호출을 통해 뽑아와서 이를 해독하였다.

### Other

```c++
std::string decodeMorse(std::string morseCode) {
  std::string decoded;
  const char* current = morseCode.data(), *end = current + morseCode.size();
  
  // Strip off all leading and trailing space first
  while (*current == ' ') current++;
  while (end[-1] == ' ') end--;
  
  while (current < end) {
    if (*current == ' ') {
      decoded += ' ';
      current += 2;
    } else {
      const char* start = current;
      while (current < end && *current == '.' || *current == '-') ++current;
      decoded += MORSE_CODE[std::string(start, current)];
      current++;
    }
  }
  return decoded;
}
```
*  정규식을 이용하지 않고 풀이한 방법이라 가져왔다.
*  포인터를 이용하여 풀이하였는데 내 풀이보다 깔끔한거 같다.
*  처음에 문자열에 앞뒤 공백을 제거해주었고
*  처음 포인터를 start 변수에 저장하고 포인터를 이용하여 공백까지 포인터를 이용해준다음 해당문자열을 해독해주었다. 그다음 start 포인터를 공백 다음 포인터로 이동해주었다.

## 배운 점

*  역시 최고는 정규식이다! sregex함수를 이용하면 해당 정규식에 해당되는 부분만 재귀로 불러올수 있다는게 너무 신기하였다.
*  초인터를 c++에서도 자주이용하는지는 모르겠지만 문자열을 다룰때는 유용한거 같다.

## Action Item

*  정규식을 자유자재로 쓰는 날이 빨리 오면 좋겠다 !