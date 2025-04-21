// 7 7
// 0 1
// 1 3
// 3 2
// 1 4
// 3 5
// 2 5
// 5 6
// 0
// 6
#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    parent[src]=-1;
    while(!q.empty())
    {
        //ber kore ana
        int par=q.front();
        q.pop();
        //oi node niye kaj kora
        for(int child : adj_list[par])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1;
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
        adj_list[b].push_back(a);
    }
    
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));

    int src,dst;
    cin>>src>>dst;
    bfs(src);

    //print shorted distance,,way to levelways
    cout<<"shorted distance -> "<<level[dst]<<endl;

    //print for path
    vector<int> path;
    int node=dst;
    while(node!=-1)
    {
        path.push_back(node);
        node=parent[node];
    }

    reverse(path.begin(),path.end());
    for(int x : path)
    {
        cout<<x<<" ";
    }
    return 0;
}