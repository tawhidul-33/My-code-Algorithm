// 6 5  /-node and edge songkha
// 0 1
// 1 2
// 2 3
// 3 0
// 4 5
#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
int parent[105];
bool cycle;

void bfs(int src)
{
    vis[src]=true;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        //ber kore ana
        int par=q.front();
        q.pop();
        //childe push kora
        for(int child:adj_list[par])
        {
            //cycle ditect
            if(vis[child] && child!=parent[par])//visited but parent na ,,tahole cycle ace nayle nai
            {
                cycle=true;
            }

            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                parent[child]=par;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);//undirected
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    if(cycle==true)
      cout<<"Cycle Detected";
    else
      cout<<"No Cycle";
    return 0;
}