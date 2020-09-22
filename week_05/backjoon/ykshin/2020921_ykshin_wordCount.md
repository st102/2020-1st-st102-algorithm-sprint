# {단어의 개수}

## 문제 설명
주어진 문자열에서 몇 개의 단어가 존재하는지 출력

## 나의 풀이 방법
1. 문자열을 읽고, StringTokenizer를 생성한다. 
2. token의 개수를 출력한다.
```kotlin
    println(StringTokenizer(BufferedReader(InputStreamReader(`in`)).readLine()).countTokens())
```

## 다른 사람의 풀이 방법
하.. 세상엔 변태가 많다.. 덕분에 이런 언어가 있다는 것을 알게 되었다.
```Golfscript
);' '%,
``` 

## 배운 점
- StringTokenizer를 사용하면 중간 공백도 제거하여 token화 해준다.

## 반성할 점
- 문제 조건 제대로 확인하자

## Action Item
- 화이팅