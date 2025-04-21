// 2 //-test case
// 9
// 1 8 3 4 0 7 6 5 2
// 5
// 5 2 1 6 3
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<int>v(n);
        //first_max
        int fmx=-1;
        for(int i=0;i<n;i++)
        {
           cin>>v[i];
           fmx=max(fmx,v[i]);
        }
        
        //last_max
        int lmx=-1;
        for(int i=0;i<n;i++)
        {
           if(v[i]!=fmx){
             lmx=max(lmx,v[i]);
           }
           
        }
        //print 
        for(int i=0;i<n;i++)
        {
           if(v[i]==fmx){
             cout<<i<<" ";
             
           }
           if(v[i]==lmx){
            cout<<i<<" ";
            
          }
           
        }
        cout<<endl;
    }
    
    return 0;
}