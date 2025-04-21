//BED
//BKE

//LCS = longest common subsequence
#include<bits/stdc++.h>
using namespace std;
string str1,str2;
int dp[105][105];
int lcs(int i,int j)
{
  //base case
  if(i<0||j<0){
    return 0;
  }
  //for dp
  if(dp[i][j]!=-1){
    return dp[i][j];
  }
  //prosesing
    if(str1[i]==str2[j]){
        int op1=lcs(i-1,j-1)+1;
        return dp[i][j]=op1;
    }
    else
    {
        int op1=lcs(i-1,j);
        int op2=lcs(i,j-1);
        return dp[i][j]=max(op1,op2);
    }

}
int main()
{
   
   cin>>str1>>str2;
   int s1=str1.size();
   int s2=str2.size();
   memset(dp,-1,sizeof(dp));
   cout<<lcs(s1-1,s2-1);
return 0;
}
