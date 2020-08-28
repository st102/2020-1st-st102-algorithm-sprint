#include <iostream>
#include <cstring>

using namespace std;
int numbers[2001],dp[2001][2001];
int start=0,last=0,question=0,num=0;
int isPalindrome(int start,int end){
    if(start==end) return true;
    else if(start==end+1) return numbers[start]==numbers[end]; 
    if(dp[start][end]!=-1) return dp[start][end];

    if(numbers[start]==numbers[end])  
        return dp[start][end]=isPalindrome(start+1,end-1);
    return dp[start][end]=false;
}
int main(){
    scanf("%d",&num);
    memset(numbers,0,sizeof(numbers));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<num;i++)
        scanf("%d",&numbers[i]);
    
    scanf("%d",&question);
    for(int i=0;i<question;i++){
        scanf("%d %d",&start,&last);
        printf("%d\n",isPalindrome(start-1,last-1));
    }
}