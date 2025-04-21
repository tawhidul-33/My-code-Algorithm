#include<bits/stdc++.h>
using namespace std;
long long int dp[1005];
long long int febo(long long int n) //O(N)
{
    if(n==0 || n==1){
        return n; //mane 0 hoile 0 ,,1 hoile 1
    }
    // or
    // if(n<2){
    //     return n; //mane 0 hoile 0 ,,1 hoile 1
    // }
    
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=febo(n-1)+febo(n-2);
    return dp[n];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<febo(n);//n er febonacci nirnoy
    return 0;
}
// febonacci seriz
//indx-> 0 1 2 3 4 5 6  7  8  9                                         
//febo-> 0 1 1 2 3 5 8 13 21 34  
//aikhane purber 2 songkhr jogfol(+) hoche porer songkha