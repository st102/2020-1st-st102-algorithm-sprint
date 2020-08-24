ECHO가 설정되어 있습니다.
# vowel count

## 문제 설명

* 1주차 : 주어진 문자열에서 모음의 개수를 출력

## 나의 풀이 방법

```c
//최초풀이

#include <stddef.h>

size_t get_count(const char *s)
{
  int vow=0; //모음의 개수를 저장할 변수
  
  
  //모음의 개수를 구하기 (switch-case 사용)
  for (int i=0;i<sizeof(s)/sizeof(char);i++){
    switch(s[i]){
        case 'a' : vow+=1;  break;
        case 'e' : vow+=1;  break;
        case 'i' : vow+=1;  break;
        case 'o' : vow+=1;  break;
        case 'u' : vow+=1;  break;
        default: break;
    }
  }
  
  return vow;
}
```
-for문에서 warning: comparison of integers of different signs: 'int' and 'unsigned long' 라는 에러가 발생했다.
	-int는 signed로 간주되고 unsigned long형과 비교하면 안된다는 건 알겠는데, 어느부분에서 unsigned long형이 발생하는지 모르겠다.
	-**int i=0** 대신에 **unsigned long i=0**라고 하니 **warning**은 없어졌지만 테스트코드 통과가 안된다.
	-**sizeof(s)/sizeof(char)** 대신에 테스트 케이스에서 **abracadabra**길이인 **11**을 넣으면 통과되는데 **50**은 안된다. 왜 이런 결과가 나오는지 잘 모르겠다.

```c
//수정 후 성공한 방법
#include <stddef.h>

size_t get_count(const char *s)
{
  int vow=0; //모음의 개수를 저장할 변수
  int len=0; //입력받은 배열의 길이를 저장할 변수
  
  //배열의 길이 구하기
  while(s[len]!=0){
    len++;
  }
  
  //모음의 개수를 구하기 (switch-case 사용)
  for (int i=0;i<len;i++){
    switch(s[i]){
        case 'a' : vow+=1;  break;
        case 'e' : vow+=1;  break;
        case 'i' : vow+=1;  break;
        case 'o' : vow+=1;  break;
        case 'u' : vow+=1;  break;
        default: break;
    }
  }
  
  return vow;
}
```
-***len***이란 변수를 받아 먼저 길이를 구했다.
-30분안에 성공해서 나름 만족했다.

## 다른 사람의 풀이 방법

```c
//Best Practices
#include <stddef.h>

size_t get_count(const char *s)
{
    size_t cnt = 0ul;
    if (!s)
        return 0ul;
    while (*s)
        switch (*s++) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++cnt;
            break;
        }
    return cnt;
}
```
-일단 먼저 `while(*s){ switch(*s++) ~~` 가 눈에 띄었다. 내 코드 보다 간단해 보였다.
	-그리고 `if(!s)	return 0ul;` 이게 테스트코드(?)인가 싶다.
-나는 vow를 **int**로 선언했는데 여기선 **size_t**로 했다.
	-signed 와 unsigned 에 대해 잘 모르는거 같아서 더 공부해야겠다.
- 그런데 '0ul'은 무슨 문법인지 잘 모르겠다.
	

```c
///clever
#include <string.h>

#define VOWELS "aeiou"
size_t get_count(const char *s)
{
    int count = 0;
    for (; *s != '\0'; s++)
        if (strchr(VOWELS, *s) != NULL) count++;
    return (count);
}
```
-매크로를 이용해 문자열 비교를 했다. 나는 switch-case문 밖에 생각하지 못했는데 새로운 해법도 알게 된 것 같다.
-`for (; *s != '\0'; s++){if (strchr(VOWELS, *s) != NULL) count++;}` 를 `while(*s){if (strchr(VOWELS, *s++) != NULL) count++;}`로 바꿔도 좋을 것 같다.


## 배운(울) 점

* 조건문안에서 식이 '0'이면 거짓 '0이 아니면' 참 이라는 점을 이용해 코드가 더 간단해 질 수 있다.
* signed 와 unsigned , size_t 에 대해 더 알아보아야 겠다. (자료형, 반환형)
* 나의 첫번째 풀이가 왜 실행되지 않는지도 알아보면 좋겠다.
* 테스트코드에 대해 더 알아보기

## 반성할 점

* 자료형을 잘 맞춰서 해야겠다.
* 배울점과 반성할 점이 비슷한 거 같다.

## Action Item

> `배운 점` 과 `반성할 점` 을 토대로, 다음 문제를 풀 때 어떤 점을 더 고려해서 할지 적어본다

* 코드 작성후 더 간단히 만들 수 있을지 한번 더 고민해보자. 
* 테스트코드 할 수 있으면 넣어보기(?)