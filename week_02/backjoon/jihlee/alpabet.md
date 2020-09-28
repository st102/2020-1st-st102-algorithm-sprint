알파벳 찾기
=========

## 문제 설명

주어진 단어에서 a부터 z까지 위치하는 인덱스를 차례로 출력하는 문제


## 나의 풀이 방법

```c++
for (int i = 97; i <= 122; i++) {
        if (word.find((char)i) > word.length())
            cout << -1 << " ";
        else
            cout << word.find((char)i) << " ";
    }
```
**아스키코드**와 find함수를 이용하여 주어진 단어 word에서 알파벳을 순서대로 찾는다. 

이문제는 단어가 모두 소문자로만 구성되어 있으므로 a의 아스키코드인 97부터 z의 아스키코드인 122까지 확인한다.

int i = 97; i <= 122; i++대신 (char i='a'; i<='z'; i++)로 사용해도 괜찮다. 

## 다른 사람의 풀이 방법
```c++
    for(int i=0; i<26; i++){
		alpa[i] = -1; 
	}
	
	int size = strlen(s); 
	
	for(int i=0; i<size; i++){
		if(alpa[(int)(s[i]-97)] == -1) {
			alpa[(int)(s[i]-97)] = i;   
		}
	}
	
	for(int i=0; i<26; i++){
		cout << alpa[i] << " ";
	}
```
이 풀이 방법은 나의 풀이와 반대로 주어진 문자에서의 알파벳을 순차적으로 탐색하여 alpa배열에 인덱스를 채워 넣는다. 

참고 사이트: <https://jaynamm.tistory.com/entry/%EB%B0%B1%EC%A4%80-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-10809%EB%B2%88-%EC%95%8C%ED%8C%8C%EB%B2%B3-%EC%B0%BE%EA%B8%B0>

## 배운점 
-아스키코드를 외우지 않아서 매번 까먹고 표를 보는데 외워둘 필요가 있는 것 같다.

-A:65 Z:90 a:97 z:122 총 알파벳은 26개
