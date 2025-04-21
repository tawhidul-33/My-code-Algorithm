// 5 6
// 1 2 2
// 2 5 5
// 2 3 4
// 1 4 1
// 4 3 3
// 3 5 1
//complixty O(logV(V+E))

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll>> adj_list[100005];
ll dis[100005];
ll parent[100005];
 void dijkstra(ll src)
{
    //priorrity_queue for optimize
    //for first priority minimum_numbar;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,src});//aikhane 0 hoilo distance
    dis[src]=0;
    while(!pq.empty())
    {
        //ber kore ana
        pair<ll,ll> par=pq.top();
        pq.pop();
        ll par_node=par.second;
        ll par_dis=par.first;
        //child push kora
        for(auto child : adj_list[par_node])
        {
            ll child_node = child.first;
            ll child_dis = child.second;
            if( par_dis+child_dis<dis[child_node])
            {
                dis[child_node]=par_dis+child_dis;
                pq.push({dis[child_node],child_node});
                //for path
                parent[child_node]=par_node;
            }
        }
    }
}
int main()
{
    ll n,e;
    cin>>n>>e;
  
    while(e--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});//undirected
    }
    for(ll i=1;i<=n;i++){
        dis[i]=LLONG_MAX;
        parent[i]=-1;
    }
    dijkstra(1);
    //print
    if(dis[n]==LLONG_MAX)//aikhane n hitache destination
    {
        cout<<"-1"<<endl;
    }
    else{
        vector<ll>path;
        ll node=n;
        while(node!=-1)
        {
           path.push_back(node);
           node=parent[node];
        }
        reverse(path.begin(),path.end());
        for(ll x:path)
        {
            cout<<x<<" ";
        }
        cout<<endl;

    }
    
    return 0;
}