#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

bool dp[10001];

void selfnumber(int num)
{
    int selfnum = num;
    while (num > 0) {
        selfnum += num % 10;
        num /= 10;
    }
    dp[selfnum] = true;
}

int main()
{
    memset(dp, false, sizeof(dp));
    for (int i = 1; i <= 10000; i++)
        selfnumber(i);

    for (int i = 1; i <= 10000; i++)
        if (!dp[i])
            cout << i << endl;
}