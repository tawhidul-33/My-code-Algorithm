// 5 3 //- n,e
// 1 2
// 1 3
// 4 5
#include<bits/stdc++.h>
using namespace std;
int par[100005];
int group_size[100005];
int cmp,mx_cmp_sz;

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
    if(leder1==leder2)
    {
            return;
    }
    if(group_size[leder1]>=group_size[leder2])
    {
        par[leder2]=leder1;
        group_size[leder1]+=group_size[leder2];
        // for_max_cpm_size
        mx_cmp_sz=max(mx_cmp_sz,group_size[leder1]);
    }else{
        par[leder1]=leder2;
        group_size[leder2]+=group_size[leder1];
        // for_max_cpm_size
        mx_cmp_sz=max(mx_cmp_sz,group_size[leder2]);
    }
    //For_cmp_num
    cmp--;
}

int main()
{
    
    int n,e;
    cin>>n>>e;
    //intialize
    for(int i=1;i<=n;i++)
    {
        par[i]=-1;
        group_size[i]=1;
    }
    
    cmp=n;
    mx_cmp_sz=1;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        dsu_union(a,b);
        cout<<cmp<<" "<<mx_cmp_sz<<endl;

        

    }
    
    return 0;
}