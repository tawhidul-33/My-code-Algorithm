// 5 8 /Node and edge songkha
// 0 1 10 //eikhane 10 hoche weighted 
// 1 2 1  //eikhane 1 hoche weighted 
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5
// 1 4 3
// 2 4 5

//complexity O(V*E)
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[105];
int dis[105];
 void dijkstra(int src)
{
    queue<pair<int,int>>q;
    q.push({src,0});//aikhane 0 hoilo distance
    dis[src]=0;
    while(!q.empty())
    {
        //ber kore ana
        pair<int,int> par=q.front();
        q.pop();
        int par_node=par.first;
        int par_dis=par.second;
        //child push kora
        for(auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;
            if( par_dis+child_dis<dis[child_node])
            {
                dis[child_node]=par_dis+child_dis;
                q.push({child_node,dis[child_node]});
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
        int a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});//undirected
    }
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }
    dijkstra(0);
    //print
    for(int i=0;i<n;i++)
    {
        cout<<i<<" of shorted distance from src -> "<<dis[i]<<endl;
        
    }
    return 0;
}