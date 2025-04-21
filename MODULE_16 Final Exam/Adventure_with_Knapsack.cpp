// 2  /-test case
// 4 7  /-n,bag_limit
// 2 3 4 5  /-weight
// 4 7 6 5  /-valu
// 4 17
// 10 1 6 9
// 6 10 10 8
#include<bits/stdc++.h>
using namespace std;
int valu[1005];
int weight[1005];
int dp[1005][1005];

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
        int op1 = valu[i]+knapsack(i-1,bag_limit - weight[i]);
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
  int t;
  cin>>t;
  while(t--)
  {
    int n,bag_limit;
    cin>>n>>bag_limit;
    //weight
    for(int i=0;i<n;i++)
      cin>>weight[i];  
    //valu 
    for(int i=0;i<n;i++)
      cin>>valu[i];

    //intialize
    for(int i=0;i<=n;i++)
    {
       for(int j=0;j<=bag_limit;j++)
       {
          dp[i][j]=-1;
       }
    }
    cout<<knapsack(n-1,bag_limit)<<endl;
  }

    
    
    return 0;
}