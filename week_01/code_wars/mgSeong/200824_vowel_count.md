# Vowel Count

## 문제 설명

*   주어진 string 내의 모음 개수를 계산한다

## 나의 풀이 방법

```c++
#include <iostream>
#include <string>

using namespace std;

int main()
{
   string sentence;
   int i = 0;
   int count = 0;

   getline(cin, sentence);
   cout << sentence << endl;

   while (sentence[i]!='\0')
   {
      if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u')
      {
         count++;
      }
      i++;
   }

   cout << "모음의 개수는 : " << count;
   
   return 0;
}

```

*   String 헤더를 사용하여 문자열을 받았습니다.
*   While문을 사용하여 문자열 끝에 가면 끝나도록 하였으며 if문으로 모음을 만났을 때 count를 세도록 하였습니다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <string>

using namespace std;

int getCount(const string& inputStr){
  return count_if(inputStr.begin(), inputStr.end(), [](const char ch) {
      switch(ch) {
          case 'a':
          case'e':
          case'i':
          case'o':
          case'u':
              return true;
          default:
              return false;} 
     });
}
```

*   나보다 적은 변수를 사용했으며 보다 단조로워보여 best practice라고 생각한다.

## 배운 점

*   함수를 사용하여 편하게 푸는 방법을 배웠다.

## 반성할 점

*   함수를 자주 애용하지 않는 부분이 있는데 다음부터 풀때는 좀 더 활용해봐야겠다.

```python
# 예전 답(약 10개월 전)

def getCount(inputStr):
    vowels  = {'a', 'e', 'i', 'o', 'u'}
    
    if len(inputStr) == 0:
        return 0
    
    temp_dict = {}
    for ele in inputStr:
        if ele in vowels:
            if temp_dict.get(ele):
                temp_dict[ele] += 1
                
            else:
                temp_dict[ele] = 1
                
    return sum(temp_dict.values())
```

*   일단 메소드 명 부터 카멜 케이스 로 적혀있는 것 부터 문제
*   나름 멤버쉽 체크를 위해서 vowels set 을 만들긴 했으나, 굳이 set 만들지 않아도 될 것 같다(개수가 적어서)
*   temp_dict를 굳이 만들어서 연산할 필요가 없음
*   Temp_dict.get(ele) 를 굳이 써서 체크할 필요 없음

위의 사항처럼 10개월 전에는 매우 비효율적으로 푼 것을 알 수 있었고, 앞으로도 저렇게 풀지 않도록 주의해야곘다

## Action Item

*   쉬운 문제일 수록, 좀 더 고민해서, 더 파이써닉 하게 풀 수 있는 방법으로 리팩토링 해서 풀자