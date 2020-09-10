# Highest and lowest

## 문제 설명

*  주어진 문자열에서 길이가 5이상인 단어를 뒤짚어 문장을 만들어라

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include<sstream>
#include<algorithm>

using namespace std;

string spinWords(const string &str)
{
    stringstream ss(str);
    string word;
    string result_sentence = "";

    while (ss >> word) {
        if (word.length() > 4) {
            reverse(word.begin(), word.end());
        }
        result_sentence += word + " ";
    }
    result_sentence.pop_back();
  
  return result_sentence;
}
```

*  stream을 이용하여 단어에 접근하여 길이가 5이상일 경우 algorithm해더에 있는 reverse 함수를 이용하여 단어를 뒤짚어 문자열을 완성하였다.

### 테스트 코드
```c++
Describe(Sample_Tests)
{
    It(test_code_single_word_length_no_more_five)
    {
        Assert::That(spinWords("to"), Equals("to"));
        Assert::That(spinWords("with"), Equals("with"));
    }
  
    It(test_code_single_word_length_more_five)
    {
        Assert::That(spinWords("Welcome"), Equals("emocleW"));
        Assert::That(spinWords("CodeWars"), Equals("sraWedoC"));
    }
    
    It(test_code_mulitple_words_composed_word_length_no_more_five)
    {
      Assert::That(spinWords("Hey fellow warriors"), Equals("Hey wollef sroirraw"));
      Assert::That(spinWords("Burgers are my favorite fruit"), Equals("sregruB are my etirovaf tiurf"));
      Assert::That(spinWords("Pizza is the best vegetable"), Equals("azziP is the best elbategev"));      
    }
  
    It(test_code_mulitple_words_with_word_length_more_five)
    {
      Assert::That(spinWords("How are you"), Equals("How are you"));
      Assert::That(spinWords("I love you"), Equals("I love you"));
    }
};
```

*  단일 단어일경우 길이가 5이상일꺠 아닐때, 문장일경우 길이가 5이상인 단어가 포함될때 아닐때를 구분하여 테스트 코드를 작성하였습니다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <string>
#include <algorithm>
#include <sstream>
std::string spinWords(const std::string &str)
{
    std::stringstream ss(str);
    std::string result;
    std::string buff;
    while (ss >> buff) {
        if (buff.size() >= 5) {
            std::reverse(buff.begin(), buff.end());
        }
        result += buff + ' ';
    }
    result.pop_back();
    return result;
}
```

### Clever

```c++
#include <string>
#include <algorithm>
#include <sstream>
std::string spinWords(const std::string &str)
{
    std::stringstream ss(str);
    std::string result;
    std::string buff;
    while (ss >> buff) {
        if (buff.size() >= 5) {
            std::reverse(buff.begin(), buff.end());
        }
        result += buff + ' ';
    }
    result.pop_back();
    return result;
}
```

*  나랑 정확히 같은 코드이다..뿌듯하다!

## 아쉬운 점

*  아직까지는 테스트 코들르 작성하고 ttd를 하는게 익숙하지 않다..

## Action Item

*  ttd를 하는게 아직은 익숙하지 않다.. 태스트 코드를 작성하여 리펙토링 하는 과정을 더 자주 이용하려고 노력하자!