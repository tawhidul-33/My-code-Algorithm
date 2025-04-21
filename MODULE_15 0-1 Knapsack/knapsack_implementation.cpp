// 4        /->n of valu and weight
// 10 4 7 5 /->valu
// 4 3 2 5  /->weight
// 8        /-bag_limit
#include<bits/stdc++.h>
using namespace std;
int valu[1005];
int weight[1005];       //O(2^N)

int knapsack(int i,int bag_limit)        
{
   //base case
    if(i<0|| bag_limit<=0)
    {
    return 0;
    }
    if(weight[i]<=bag_limit)
    {
        //2 option
        //option 1 bag a rakbo,,option 2 bag a rakbona
        int op1 = knapsack(i-1,bag_limit - weight[i])+valu[i];
        int op2 = knapsack(i-1,bag_limit);
        return max(op1,op2);
    }
    else{
      //1 option
      // bag a rakte parbona
      int op2 = knapsack(i-1,bag_limit);
      return op2;
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
    
    cout<<knapsack(n-1,bag_limit)<<endl;
    return 0;
}


