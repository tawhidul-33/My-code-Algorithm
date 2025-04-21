// 6 6 //n,,e
// 0 1
// 1 2
// 0 4
// 4 5
// 5 3
// 3 4
#include<bits/stdc++.h>
using namespace std;
int led[1005];
int group_size[1005];
int find(int node)//O(logN)
{
    //base case
    if(led[node]==-1){
        return node;
    }
    
    int leder=find(led[node]);
    led[node]=leder;
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
    int n,e;
    cin>>n>>e;
    bool cycle=false;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        int lederA=find(a);
        int lederB=find(b);
        if(lederA==lederB){
            cycle=true;
        }
        else{
            dsu_union(a,b);
        }
    }
    
    if(cycle==true){
        cout<<"cycle ditected"<<endl;
    }else{
        cout<<"Not cycle ditected"<<endl;
    }
    return 0;
}