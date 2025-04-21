// 4 7
// 1 2 10
// 2 3 5
// 3 4 2
// 4 2 3
// 3 1 7
// 2 1 1
// 1 4 4
// 6
// 1 2
// 4 1
// 3 1
// 1 4
// 2 4
// 4 2
#include<bits/stdc++.h>
using namespace std;
long long int adj_mat[105][105];
int n,e;

void floyd_warshall()
{
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
}

int main()
{
    
    cin>>n>>e;
    //intialize
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
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
        //adj_mat[b][a]=min(adj_mat[b][a],c);;  //undirected
    }

    floyd_warshall();
    //query
    int q;
    cin>>q;
    while(q--)
    {
        int s,d;
        cin>>s>>d;
        
        if(adj_mat[s][d]==LLONG_MAX){
            cout<<"-1"<<endl;
        }else{
            cout<<adj_mat[s][d]<<endl;
        }
    }
    return 0;
}