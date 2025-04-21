// 4
// 1 2 4 6
// 7
#include<bits/stdc++.h>
using namespace std;
int val[105];
int dp[105][105];
bool sub_set(int i,int sum) //O(N*sum)
{
    //base case
    if(i<0){
        if(sum==0)return true;
        else return false;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    if(val[i]<=sum)
    {
        bool op1=sub_set(i-1,sum-val[i]);
        bool op2=sub_set(i-1,sum);
        dp[i][sum]=op1||op2;
        return dp[i][sum];
    }else{
        dp[i][sum]=sub_set(i-1,sum);
        return dp[i][sum];
    }
    
}
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cin>>val[i];
   }
   int sum;
   cin>>sum;

   memset(dp,-1,sizeof(dp));

   if(sub_set(n-1,sum))
   cout<<"YES subset_possible";
   else cout<<"No subset_Not_possible";
return 0;
}
