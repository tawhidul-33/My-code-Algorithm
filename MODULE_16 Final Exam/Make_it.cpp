// 5 /-> test case
// 1
// 3
// 5
// 15
// 16
#include<bits/stdc++.h>
using namespace std;
int dp[100005];
bool can_reach(int start,int target)
{
   if(start>target) return false;
   if(start==target)return true;

   if(dp[start]!=-1){
    return dp[start];
   }

    dp[start]=can_reach(start+3,target)||can_reach(start*2,target);
    return dp[start];
}
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       memset(dp,-1,sizeof(dp));
       if(can_reach(1,n))
          cout<<"YES"<<endl;
       else
          cout<<"NO"<<endl;
    }
    return 0;
}
