피보나치수5 
=========

## 문제 설명

20 이하의 피보나치수 구하기 


## 나의 풀이 방법

```c++
#include <iostream>
using namespace std;

int main(){
    cin>>n;
    memset(dp,0,sizeof(dp));
    dp[1]=dp[2]=1;
    for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n]<<endl;
}
```
**DP**을 사용하여 dp배열의 0,1,2 인덱스를 0,1,1로 초기화하여
3부터 구하고자하는 n의 인덱스까지 **dp[i]=dp[i-1]+dp[i-1]** 공식을 이용하여 채웠습니다. 

## 다른 사람의 풀이 방법
```c++
int f(int num)
{
    static int mem[21];
    if (mem[num] != 0) return mem[num];
    if (num == 0 ) return mem[0];
    if (num == 1) return mem[num]=1;
    return mem[num] = f(num - 1) + f(num - 2);
}
```
이 풀이 방법 또한 DP를 사용하는데 반복문 대신 재귀함수를 이용하여 dp배열을 채웠습니다.
DP를 사용한 경우 시간 복잡도를 **O(n)** 으로 까지 줄일 수 있어 효율적입니다. 
다른 사람 풀이 사이트: <https://codecollector.tistory.com/160>

## 배운점 
DP를 사용하는 방법은 여러가지가 있는데 그중에서 재귀함수로도 dp배열을 채울 수 있다는 것을 알게 되었습니다. 
