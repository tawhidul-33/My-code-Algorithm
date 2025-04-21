// 5 4
// ....
// ---.
// ..-.
// --..
// ....
// 0 1 // si,,sj
// 3 2//di,,dj
#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n,m;
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
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    dfs(si,sj);

    if(vis[di][dj]==true){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}