//Note : You must solve this problem using Recursion. (Top Down)
// 4
//or
//5
#include<bits/stdc++.h>
using namespace std;
int dp[35];
int tetranacci(int n)
{
    if(n==0||n==1){
        return n;
    }
    if(n==2)return 1;
    if(n==3)return 2;
      

if(dp[n]!=-1){
    return dp[n];
}

    dp[n]=tetranacci(n-1)+tetranacci(n-2)+tetranacci(n-3)+tetranacci(n-4);
    return dp[n];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<tetranacci(n);
    return 0;
}