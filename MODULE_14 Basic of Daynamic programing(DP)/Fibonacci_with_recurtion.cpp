#include<bits/stdc++.h>
using namespace std;
int febo(int n) //O(2^N)
{
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    
    return febo(n-1)+febo(n-2);
}
int main()
{
    cout<<febo(5);//5 er febonacci nirnoy
    return 0;
}
// febonacci seriz
//indx-> 0 1 2 3 4 5 6  7  8  9                                         
//febo-> 0 1 1 2 3 5 8 13 21 34  
//aikhane purber 2 songkhr jogfol(+) hoche porer songkha