// 5 5
// 1 2
// 1 3
// 1 4
// 2 3
// 5 4
#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int parent[100005];

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    parent[src]=-1;
    while(!q.empty())
    {
        //ber kore ana
        int par=q.front();
        q.pop();
        //child push kora
        for(int child : adj_list[par])
        {
            if(vis[child]==false)
            {
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
        adj_list[b].push_back(a);
    }
    
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));

    int src,dst;
    //cin>>src>>dst;
    src=1;dst=n;
    bfs(src);


    //print path 
    if(vis[dst]==false)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector<int> path;
        int node=dst;
        while(node!=-1)
        {
          path.push_back(node);
          node=parent[node];
        }
        
        cout<<path.size()<<endl;

        reverse(path.begin(),path.end());
        for(int x : path)
        {
          cout<<x<<" ";
        }

    }
    
    return 0;
}