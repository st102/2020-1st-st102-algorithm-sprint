연구소
=========

## 문제 설명

주어진 수열에서 시작과 끝점에 해당하는 구간의 숫자들이 팰린드롬(앞과 뒤로 읽어도 모두 동일한 숫자)인지 출력하는 문제이다. 


## 나의 풀이 방법

```c++
int isPalindrome(int start,int end){
    if(start==end) return true;
    else if(start==end+1) return numbers[start]==numbers[end]; 
    if(dp[start][end]!=-1) return dp[start][end];

    if(numbers[start]==numbers[end])  
        return dp[start][end]=isPalindrome(start+1,end-1);
    return dp[start][end]=false;
}
```
**재귀함수**를 이용하여 시작과 끝지점에 숫자가 같은지 확인하고 같으면 dp배열에 다음 인덱스의 isPalindrome의 반환값을 넣고 반환하고 다르면 false을 반환 dp 배열에 넣고 반환하도록 한다.  

## 다른 사람의 풀이 방법
```c++
int go(int s,int e)
{
	if(s >= e) return 1;
	int &ref = d[s][e];
	if(ref != -1) return ref;
    
	if(a[s] == a[e]) 
        return ref = go(s+1,e-1);
	else
		return ref = 0;
}
```
이 풀이 방법은 방법은 나의 풀이와 똑같으나 사용한 문법이 신기했다. int &ref로 d배열의 메모리 주소를 가져와서 재귀함수로 반환한 값을 ref변수 안에다가 넣으면 d[s][e]에 알아서 들어간다. 유용하게 사용할 수 있을 것 같다. 

참고 사이트: <https://www.acmicpc.net/board/view/34345>

## 배운점 

-처음에 재귀함수와 dp배열에 메모제이션을 하지 않고 while문으로 매번 검사를 했더니 시간초과가 났다. 크기가 큰 편이 아닌데 시간 제한이 0.5초여서 찾을 구간이 많으면 시간 초과가 나는 것 같다. 

-무한루프에 자주 빠져서 재귀함수를 평소에 사용하지 않았는데 자주 사용하다보니 패턴에 익숙해지는 것 같다.

-int& ref=dp[s][e]로 재귀함수를 반환값을 깊은 복사로 저장하는 법을 알게 되었다. 