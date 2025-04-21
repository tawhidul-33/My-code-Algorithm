// 4
// 1 2 4 6
// 7
#include<bits/stdc++.h>
using namespace std;
int val[105];
bool sub_set(int i,int sum)//O(2^N)
{
    //base case
    if(i<0){
        if(sum==0)return true;
        else return false;
    }
    if(val[i]<=sum)
    {
        bool op1=sub_set(i-1,sum-val[i]);
        bool op2=sub_set(i-1,sum);
        return op1||op2;
    }else{
        return sub_set(i-1,sum);
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
   if(sub_set(n-1,sum))
   cout<<"YES subset_possible";
   else cout<<"No subset_Not_possible";
return 0;
}
