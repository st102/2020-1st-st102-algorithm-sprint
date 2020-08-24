#include<iostream>
#include<cmath>
using namespace std;
int dp[21], N=0;

int main(int argc, char** argv)
{
   cin >> N;
   cout << (pow(((1 + sqrt(5)) / 2), N) - pow(((1 - sqrt(5)) / 2), N)) / sqrt(5) << endl;
}