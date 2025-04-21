 // 4 4 /-node and edge songkha
// 0 1
// 1 2
// 2 3
// 0 3
#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
bool path_vis[105];//for cycle detected from Direct graph
bool cycle;

void dfs(int src)
{
    vis[src]=true;
    path_vis[src]=true;
    for(int child:adj_list[src])
    {
          //detect cycle
          if(vis[child] && path_vis[child]==true ){
           cycle=true;
          }

        if(!vis[child])
        {
            
            dfs(child);
            
        }
    }
    path_vis[src]=false;
}

int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);//directed
    }
    memset(vis,false,sizeof(vis));
    memset(path_vis,false,sizeof(path_vis));
    cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(cycle==true)
      cout<<"Cycle Detected";
    else
      cout<<"No Cycle";
    return 0;
}