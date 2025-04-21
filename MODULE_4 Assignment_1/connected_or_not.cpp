// 5 6
// 0 1
// 1 2
// 2 3
// 3 4
// 1 4
// 0 2
// 10 /- query songkha
// 0 1
// 1 0
// 2 2
// 2 3
// 0 3
// 3 0
// 1 4
// 4 1
// 4 3
// 1 2
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int adj_mat[n][n];
    memset(adj_mat,0,sizeof(adj_mat));

    //diagonal er man 1 korte hobe
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                adj_mat[i][j]=1;
            }
        }
    }

    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_mat[a][b]=1;
    }
    //query
    int query;
    cin>>query;
    while (query--)
    {
        int x,y;
        cin>>x>>y;
        if(adj_mat[x][y]==1){
            cout<<"YES Connected"<<endl;
        }else{
            cout<<"NO NOT_Connected"<<endl;
        }
    }
    
    return 0;
}
