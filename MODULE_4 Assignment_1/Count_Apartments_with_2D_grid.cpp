// 5 8 /->row and colum
// ########
// #..#...#
// ####.#.#
// #..#...#
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
     if(valid(ci,cj)==true && !vis[ci][cj]&&grid[ci][cj]=='.'){
        vis[ci][cj]=true;
        dfs(ci,cj);
     }
   }
}
int main()
{
    int si,sj;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='.'){
                si=i;
                sj=j;
            }
            
        }
    }
    memset(vis,false,sizeof(vis));
    //nuber of Apaerment
    int Apaerment_num=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&grid[i][j]=='.'){
            Apaerment_num++; 
            dfs(i,j);
             
            }
        }
        
    }
    cout<<"Apaerment_num -> "<<Apaerment_num<<endl;
    return 0;
}