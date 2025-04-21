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
    int adj_mat[n][n];

    ////initialise 0 dara
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         adj_mat[i][j]=0;
    //     }
    // }
    //or
    memset(adj_mat,0,sizeof(adj_mat));

    //diagonal er man 1 korar jonno
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j){
                adj_mat[i][j]=1;
            }
            
        }
    }

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj_mat[a][b]=1;//directed
    }
    //print
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}