// 4 3 5 // n,e,query
// 1 2 5
// 1 3 9
// 2 3 3
// 1 2 //querys
// 2 1
// 1 3
// 1 4
// 3 2
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e,q;
    cin>>n>>e>>q;
    long long int adj_mat[n+5][n+5];
    //intialize
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j){
                adj_mat[i][j]=0;
            }else{
                adj_mat[i][j]=LLONG_MAX;
            }
        }
    }
    while(e--)
    {
        long long int a,b,c;
        cin>>a>>b>>c;
        adj_mat[a][b]=min(adj_mat[a][b],c);
        adj_mat[b][a]=min(adj_mat[b][a],c);;  //undirected
    }
    
    //Floyd_Warshall
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
               if(adj_mat[i][k]!=LLONG_MAX && adj_mat[k][j]!=LLONG_MAX && adj_mat[i][k]+adj_mat[k][j]<adj_mat[i][j])
               {
                adj_mat[i][j]=adj_mat[i][k]+adj_mat[k][j];
               }
            }
       
         }
     
    }


    //query input and shortest_distance print
    while(q--)
    {
        int s,d;
        cin>>s>>d;
        if(adj_mat[s][d]==LLONG_MAX){
            cout<<-1<<endl;
        }else{
            cout<<adj_mat[s][d]<<endl;
        }
    }
   
    return 0;
}