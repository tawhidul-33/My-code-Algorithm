// 5 5 // first ta Node songkha,second ta edge songkha
// 0 1
// 0 2
// 3 0
// 1 3 
// 3 4
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> adj_list[n];//arry of vector
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);//undirected
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> ";
        for(int x:adj_list[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}