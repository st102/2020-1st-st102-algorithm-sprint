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
cin>>N;
cout<<(pow(((1 + sqrt(5)) / 2), N) - pow(((1 - sqrt(5)) / 2), N)) / sqrt(5))<<endl;
```
재창이의 풀이 방법으로 DP를 사용하지 않고 피보나치수열의 일반항을 구하여 N을 대입하여 바로 N의 피보나치 수를 구합니다.  
![피보나치 일반항](https://steemitimages.com/1280x0/https://steemitimages.com/DQmV9zKqXg25D5xjmEHk3t26x9ztFVGBEMxBn9N6Ggm1a7X/image.png)

## 배운점 
일반항을 사용하면 시간 복잡도를 **O(n)에서 O(1)** 까지 줄일 수 있다는 것을 알았습니다. 
DP문제 풀이에서 일반항을 찾아 대입하면 시간이 훨씬 빨라지는 것을 알게 되었습니다. 
