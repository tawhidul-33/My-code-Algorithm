// 3       /->n of valu and weight
// 5 3 2 /->valu
// 4 2 3  /->weight
// 6       /-bag_limit
#include<bits/stdc++.h>
using namespace std;
int valu[1005];
int weight[1005];
int dp[1005][1005];
                     //O(N*W)
int knapsack(int i,int bag_limit)        
{
   //base case
    if(i<0|| bag_limit<=0)
    {
    return 0;
    }
    if(dp[i][bag_limit]!=-1){
        return dp[i][bag_limit];
    }
    if(weight[i]<=bag_limit)
    {
        //2 option
        //option 1 bag a rakbo,,option 2 bag a rakbona
        int op1 = valu[i]+knapsack(i,bag_limit - weight[i]);//oi tai bar bar nibe ai jonno 
        int op2 = knapsack(i-1,bag_limit);
        dp[i][bag_limit] = max(op1,op2);
        return dp[i][bag_limit];
    }
    else{
      //1 option
      // bag a rakte parbona
      dp[i][bag_limit] = knapsack(i-1,bag_limit);
      return dp[i][bag_limit];
    } 

}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>valu[i];
    for(int i=0;i<n;i++)
      cin>>weight[i];  
    int bag_limit;
    cin>>bag_limit;

    //intialize
    for(int i=0;i<=n;i++)
    {
     for(int j=0;j<=bag_limit;j++)
     {
         dp[i][j]=-1;
     }
    }
    
    cout<<knapsack(n-1,bag_limit)<<endl;
    return 0;
}