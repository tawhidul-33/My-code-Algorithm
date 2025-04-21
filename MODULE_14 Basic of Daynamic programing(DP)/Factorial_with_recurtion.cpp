#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n==1){
        return 1;
    }
    int mul=fact(n-1);
    return n*mul;
}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);// n er factorial nirnoy
    return 0;
}
//5 er fectorial mane 
// 5!=5*4*3*2*1
//5!=120