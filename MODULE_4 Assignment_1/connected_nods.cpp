// 8 6 /- first a node songkha second a edge songkha
// 1 2
// 0 5
// 2 3
// 6 7
// 4 5
// 1 3
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> adj_list[n];
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);//undirected
    }
    //query
    int query;
    cin>>query;
    while(query--)
    {
        int par;
        cin>>par;
        vector<int>v;
        if(!adj_list[par].empty())
        {
           for(int child : adj_list[par])//adj_list[par] ai indx er arry theke vector er man ber kora
           {
              v.push_back(child);
           } 
        }else{
            cout<<"-1";
        }
        

        sort(v.begin(),v.end(),greater<int>());
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}