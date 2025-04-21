// 5
// 30 9 1 7 4
#include<bits/stdc++.h>
using namespace std;
void divide(int ar[],int l,int r)
{
    for(int i=l;i<=r;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
    //base case
    if(l>=r){
        return;
    }
    int mid=(l+r)/2;
    divide(ar,l,mid);
    divide(ar,mid+1,r);
}
int main()
{
   int n;
   cin>>n;
   int ar[n];
   for(int i=0;i<n;i++)
   {
    cin>>ar[i];
   }
   divide(ar,0,n-1);
return 0;
}
