// 7 5
// 0 1
// 1 3
// 3 2
// 4 6
// 3 5
// 0 /-source
// 4 /-destination
#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];//globaly diglier
bool vis[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        //ber kore ana
        int per = q.front();
        q.pop();
        // oi node niye kaj kora
        cout<<per<<" ";
        //child push kora
        for(int child : adj_list[per])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
            }
            
        }
    }
    cout<<endl;
}
int main()
{
    int n,e;
    cin>>n>>e;
    
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);// for undirected
    }
    memset(vis,false,sizeof(vis));
    int src,dst;
    cin>>src>>dst;
    bfs(src);
    if(vis[dst]==true){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}