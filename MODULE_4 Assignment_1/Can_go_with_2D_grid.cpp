// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########
#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n,m;
bool valid(int i,int j){
    if(i<0||i>=n||j<0||j>=m){
        return false;
    }
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
     if(valid(ci,cj)==true && !vis[ci][cj]&&grid[ci][cj]!='#'){
        vis[ci][cj]=true;
        dfs(ci,cj);
     }
   }
}
int main()
{
    int si,sj,di,dj;
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                si=i;
                sj=j;
            }
            if(grid[i][j]=='B'){
                di=i;
                dj=j;
            }
        }
    }
    memset(vis,false,sizeof(vis));
    dfs(si,sj);

    //destinaton a jayte parche kina cheking,,visit hoile true nayle false
    if(vis[di][dj]==true){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}