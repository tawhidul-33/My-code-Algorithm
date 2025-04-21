// 5 7
// 0 1 2
// 2 4 4
// 0 3 3
// 1 4 5
// 0 2 3
// 1 2 7
// 4 3 6
#include<bits/stdc++.h>
using namespace std;
int led[1005];
int group_size[1005];
class edge
{
    public:
    int a,b,c;
    edge(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
};

bool cmp( edge l,edge r){
    return l.c<r.c;
}

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
{   memset(led,-1,sizeof(led));
    memset(group_size,1,sizeof(group_size));

   vector<edge> edg_lis;
   int n,e;
   cin>>n>>e;
   int a,b,c;
   while(e--)
   {
     cin>>a>>b>>c;
     edg_lis.push_back(edge(a,b,c));
   }
   sort(edg_lis.begin(),edg_lis.end(),cmp);

   int total_cost=0;
   for(auto ed: edg_lis)
   {
    int par1=find(ed.a);
    int par2=find(ed.b);
    if(par1!=par2){
        dsu_union(ed.a,ed.b);
        total_cost+=ed.c;
    }
   }
   cout<<total_cost<<endl;
   
return 0;
}