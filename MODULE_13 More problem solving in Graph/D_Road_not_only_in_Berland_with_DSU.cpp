// 7
// 1 2
// 2 3
// 3 1
// 4 5
// 5 6
// 6 7
#include<bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];

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
       
    }else{
        par[leder1]=leder2;
        group_size[leder2]+=group_size[leder1];
   
    }
    
}

int main()
{
    int n;
    cin>>n;
    //intialize
    for(int i=1;i<=n;i++)
    {
        par[i]=-1;
        group_size[i]=1;
    }
    
    vector<pair<int,int>>rood_rmv;
    vector<pair<int,int>>rood_create;
    for(int i=0;i<n-1;i++)//childe_input
    {
        int a,b;
        cin>>a>>b;
        //cheking
        int leder1=find(a);
        int leder2=find(b);
        if(leder1==leder2)
        {
           rood_rmv.push_back({a,b});//remove
        }else{
            dsu_union(a,b);
        }
    }

    //rood_creating
    for(int i=2;i<=n;i++){
        int leder1=find(1);//intialy je kno akti node(jemon 1) dhora
        int leder2=find(i);
        if(leder1!=leder2)
        {
            rood_create.push_back({1,i});
            dsu_union(1,i);  
        }
    }
    //print
    cout<<rood_rmv.size()<<endl;
    for(int i=0;i<rood_rmv.size();i++)
    {
        cout<<rood_rmv[i].first<<" "<<rood_rmv[i].second<<" "<<rood_create[i].first<<" "<<rood_create[i].second<<endl;;
    }
    
    
    return 0;
}