// 5 8 /Node and edge songkha
// 0 1 10 //eikhane 10 hoche weighted 
// 1 2 1  //eikhane 1 hoche weighted 
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5
// 1 4 3
// 2 4 5
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adj_list[n];
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});//undirected
    }
    //print
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> ";
        for(pair<int,int> p : adj_list[i])
        {
            cout<<p.first<<" weight:"<<p.second<<",";
        }
        cout<<endl;
    }
    return 0;
}