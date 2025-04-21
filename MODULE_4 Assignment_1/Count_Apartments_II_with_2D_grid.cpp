// 5 8 /->row and colum
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########
#include<bits/stdc++.h>
using namespace std;
char grid[1002][1002];
bool vis[1002][1002];
int n,m;
bool valid(int i,int j){
    if(i<0||i>=n||j<0||j>=m){
        return false;
    }
    return true;
}

vector<pair<int,int>>mov={{-1,0},{1,0},{0,1},{0,-1}};
int Apaerment_room_num;
void dfs(int si,int sj)
{
   vis[si][sj]=true;
    Apaerment_room_num++;

    //child ber kora
   for(int i=0;i<4;i++)
   {
     int ci=si+mov[i].first;
     int cj=sj+mov[i].second;
     //child push kora
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

    //nuber of Apaerment_room
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(!vis[i][j]&&grid[i][j]=='.')
            {
              Apaerment_room_num=0;
             dfs(i,j);
             v.push_back(Apaerment_room_num);
            }
        }
    }
    
    if(!v.empty()){
        sort(v.begin(),v.end());
       for(int x:v){
        cout<<x<<" ";
       } 
    }else{
        cout<<"0"<<" ";
    }
    

    return 0;
}