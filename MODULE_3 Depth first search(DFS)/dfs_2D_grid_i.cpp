#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
vector<pair<int,int>>mov={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int si,int sj)
{
  cout<<si<<" "<<sj<<endl;
  vis[si][sj]=true;

  for(int i=0;i<4;i++){
    int ci,cj;
    ci=si+mov[i].first;
    cj=sj+mov[i].second;
    cout<<ci<<" "<<cj<<endl;

  }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int si,sj;//si== src i,,sj==src j
    cin>>si>>sj;
    dfs(si,sj);
    return 0;
}