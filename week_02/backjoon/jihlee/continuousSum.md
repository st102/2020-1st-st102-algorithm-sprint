연속합
=========

## 문제 설명

수열의 중 최대의 연속합을 구하는 문제


## 나의 풀이 방법

```c++
    maxSum = dp[0] = arr[0];

    for (int i = 1; i < arrNum; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maxSum = max(maxSum, dp[i]);
    }
    
    cout << maxSum << endl;
```
**1차원 DP**를 이용하여 dp[i-1]에 자신의 배열값인 arr[i]를 더해서 구간을 늘리는 것이 큰지 아니면 늘리지 않고 자신의 값 arr[i]가  다시 첫 연속 구간의 시작으로 잡는 것이 큰지 비교해여 dp[i] 값을 채우도록 한다. 그리고 dp배열에서 가장 큰 값을 maxSum에 업데이트 한다.  


## 다른 사람의 풀이 방법
```c++
 int findsumMax(const vector<int>& arr) {
    vector<int> dp(arr.size());
    dp[0] = arr[0];

    for (int i = 1; i < arr.size(); ++i)
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
    sort(begin(dp), end(dp));

    return dp.back();
}
```
이 풀이 방법은 dp자료형을 벡터로 해서 최대값을 벡터 정렬을 이용해서 구했다. dp로 접근하지 않으면 시간초과가 나기 쉬워서 대부분의 풀이가 dp를 이용해서 푼 것 같다. 

참고 사이트: <https://jaynamm.tistory.com/entry/%EB%B0%B1%EC%A4%80-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-10809%EB%B2%88-%EC%95%8C%ED%8C%8C%EB%B2%B3-%EC%B0%BE%EA%B8%B0>

## 배운점 
-처음에 문제를 연속 구간에 관한 문제여서 투포인터기법을 사용하여 풀려고 했다. 하지만 투포인터는 배열에 모든 종류가 포함된 경우,연속합이 M인 경우와 같이 고정된 조건이 경우는 가능하다. 조건이 최대/최소값에 관한 것인 경우 유동적으로 변하는 조건은 적용이 안된다는 것을 알았다.

-그리고 두번째시도 했던 방법은 2차원의 dp를 사용해서 풀려고 시도 했다. 하지만 수열의 최대 크기가 100001임으로 2차원 배열을 사용했을 때 100001*100001가 되어 메모리 초과가 나서 시간을 많이 사용했었다. 무작정 바로 2차원 dp를 사용하는 것은 좋지 않은 것같다. 

 