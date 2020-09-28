//투포인터는 조건에 만족한 경우 start를 한칸씩 옮기는데 이때 조건이 고정적인 것이여만
//투포인터가 성립이 가능하다. 조건이 최대/최소값에 관한 것인 경우 유동적임으로 적용이 안된다.
//하지만 배열에 모든 종류가 포함된 경우,연속합이 M인 경우와 같이 고정된 조건이 경우는 가능하다.

#include <iostream>

#include <cstring>

#include <algorithm>

using namespace std;
int arr[100001], dp[100001];

int main()
{
    int arrNum = 0, maxSum = -1001;
    cin >> arrNum;
    for (int i = 0; i < arrNum; i++)
        cin >> arr[i];

    memset(dp, 0, sizeof(dp));
    maxSum = dp[0] = arr[0];

    for (int i = 1; i < arrNum; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maxSum = max(maxSum, dp[i]);
    }
    
    cout << maxSum << endl;
}