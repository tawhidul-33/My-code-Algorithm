// 4 5
// 0 1 3
// 2 0 -6
// 1 2 2
// 1 3 5
// 2 3 4
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int adj_mat[n][n];
    //intialize
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j){
                adj_mat[i][j]=0;
            }else{
                adj_mat[i][j]=INT_MAX;
            }
        }
    }
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj_mat[a][b]=c;
        //adj_mat[b][a]=c; if undirected
    }

    
    
    //Floyd_Warshall
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(adj_mat[i][k]!=INT_MAX && adj_mat[k][j]!=INT_MAX && adj_mat[i][k]+adj_mat[k][j]<adj_mat[i][j])
               {
                adj_mat[i][j]=adj_mat[i][k]+adj_mat[k][j];
               }
            }
       
         }
     
    }

    //cycle ditected
    bool cycle=false;
    for(int i=0;i<n;i++){
        if(adj_mat[i][i]<0)//diagonal er man negetive hoile cycle ace
        {
            cycle=true;
        }
    }
    //print
    if(cycle==true){
        cout<<"Negetive_weighted_Cycle"<<endl;
    }else{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(adj_mat[i][j]==INT_MAX){
                   cout<<"INF"<<" ";
                }else{
                  cout<<adj_mat[i][j]<<" ";
               }
            }
          cout<<endl;
        }
        cout<<"NOT_Negetive_weighted_Cycle"<<endl;
    }
    
    
    return 0;
}