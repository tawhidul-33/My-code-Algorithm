#include<bits/stdc++.h>
using namespace std;
int led[1005];
int find(int node)//O(logN)
{
    //cout<<node<<endl;
    //base case
    if(led[node]==-1){
        return node;
    }
    
    int leder=find(led[node]);
    led[node]=leder;//optimize
    return leder;
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

    cout<<"leder-> "<<find(4)<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<i<<"->"<<led[i]<<endl;
    }

    return 0;
}