# 백준 10809 <알파벳 찾기>

## 문제 설명
입력된 문자열에 대해서 a~z까지 알파벳 중 가장 제일 먼저 나오는 자리수 출력


## 나의 풀이법
```c++

string str;
cin >> str;

int answer[26];
memset(answer, -1, 26 * sizeof(int));

for (int i = 0; i < str.size(); i++) {
	int n = (int)str[i] - 97;

	if (answer[n] == -1)
		answer[n] = i;
}

for (int i = 0; i < 26; i++)
	cout << answer[i] << ' ';
cout << '\n';

** 모든 배열 -1로 초기화 한 이후 해당 글자에 대해서 아스키 코드값 통해 배열에 저장시켜 주었다.


## 다른 사람의 풀이 방법

string a;
int result[101];
int ALPHA = 97;
int len = (int)'z' - (int)'a' + 1; //26

cin >> a;

for (int i = 0; i < len; i++)
	result[i] = -1;

for (int i = 0; i < len; i++) {
	for (int j = 0; j < a.size(); j++) {
		if (a[j] == ALPHA) {
			result[ALPHA - 97] = j;
			break;
		}
	}
	ALPHA++;
}

for (int i = 0; i < len; i++)
	cout << result[i] << ' ';
cout << '\n';

** 이 방식은 a~z까지 모든 알파벳에 대해 접근하는 하여 값을 넣어주는 방식이다.


## 배운점
** 'a'의 아스키 코드값이 97이라는 것 상기 시켜주었다. 이번 문제에서 처음으로 memset을 사용해 보았다.


