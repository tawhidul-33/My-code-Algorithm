#include<bits/stdc++.h>
using namespace std;
int led[1005];
int find(int node)
{
    while(led[node]!=-1)//O(N)
    {
        cout<<node<<endl;
        node=led[node];

    }
    return node;
}
int main()
{
    memset(led,-1,sizeof(led));
    led[0]=1;
    led[1]=-1;
    led[2]=1;
    led[3]=1;
    led[4]=5;
    led[5]=3;

    int leder=find(4);
    cout<<"leder-> "<<leder<<endl;

    return 0;
}