#include<bits/stdc++.h>
using namespace std;
int led[1005];
int group_size[1005];
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
void dsu_union(int node1,int node2)
{
    int leder1=find(node1);
    int leder2=find(node2);
    if(group_size[leder1]>=group_size[leder2])
    {
        led[leder2] = leder1;
        group_size[leder1] += group_size[leder2];
    }
    else{
        led[leder1] = leder2;
        group_size[leder2] += group_size[leder1];
    }
}
int main()
{
    memset(led,-1,sizeof(led));
    memset(group_size,1,sizeof(group_size));
    dsu_union(1,2);
    dsu_union(2,0);
    dsu_union(3,1);
    

    
    for(int i=0;i<6;i++)
    {
        cout<<i<<"->"<<led[i]<<endl;
    }

    return 0;
}