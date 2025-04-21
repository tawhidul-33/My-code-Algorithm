// 6 5
// ..-..
// ..-..
// -----
// .-...
// .----
// .....
#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n,m,cnt;
bool valid(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m)
        return false;
    else
        return true;
}
vector<pair<int,int>>mov={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int si,int sj)
{
    vis[si][sj]=true;
    cnt++;
    for(int i=0;i<4;i++)
    {
       int ci=si+mov[i].first;
       int cj=sj+mov[i].second;
       
       if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='.'){
        dfs(ci,cj);
    }
    }
    

}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int mn=INT_MAX;
    bool flag=false;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!vis[i][j] && grid[i][j]=='.'){
            flag=true;
            cnt=0;
            dfs(i,j);
            mn=min(mn,cnt);

        }
    }
   }
   if(flag==true){
    cout<<mn<<endl;
   }else{
    cout<<-1<<endl;
   }
   
    

    
    return 0;
}