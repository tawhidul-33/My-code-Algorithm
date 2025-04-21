// 5 7//n,,e
// 1 2
// 2 3
// 3 4
// 4 5
// 4 1
// 2 4
// 5 3
#include<bits/stdc++.h>
using namespace std;
int par[100005];
int group_size[100005];

//Find
int find(int node)
{
    //base case
    if(par[node]==-1)
    {
        return node;
    }

    int leder = find(par[node]);
    par[node]=leder;
    return leder;
}

//Union
void dsu_union(int node1,int node2)
{
    int leder1=find(node1);
    int leder2=find(node2);
    if(group_size[leder1]>=group_size[leder2])
    {
        par[leder2]=leder1;
        group_size[leder1]+=group_size[leder2];
    }else{
        par[leder1]=leder2;
        group_size[leder2]+=group_size[leder1];
    }
}

int main()
{
    memset(par,-1,sizeof(par));
    memset(group_size,1,sizeof(group_size));
    int n,e;
    cin>>n>>e;
    int cycle_cnt=0;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        int leder1=find(a);
        int leder2=find(b);
        if(leder1==leder2){
            cycle_cnt++;
        }else{
            dsu_union(a,b);
        }

    }
    cout<<cycle_cnt<<endl;
    return 0;
}