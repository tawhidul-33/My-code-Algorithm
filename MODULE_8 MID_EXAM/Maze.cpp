// 5 6
// ...D.#
// .R...#
// ....#.
// ..#...
// .#.##.
#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
pair<int,int>parent[1005][1005];
int n,m;
bool valid(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m)
        return false;
    else
        return true;
}
vector<pair<int,int>>mov={{0,1},{0,-1},{1,0},{-1,0}};
void bfs(int si,int sj)
{
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj]=true;
    parent[si][sj]={-1,-1};
    
    while(!q.empty())
    {
        //ber kore ana
        pair<int,int>par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        

        //child push kora
        for(int i=0;i<4;i++)
        {
            int ci=par_i+ mov[i].first;
            int cj=par_j+ mov[i].second;
            
            if(valid(ci,cj)  && vis[ci][cj]==false&&grid[ci][cj]!='#')
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                parent[ci][cj]={par_i,par_j};
            }
        }
    }

}

int main()
{

        cin>>n>>m;
        int si,sj,di,dj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              cin>>grid[i][j];
              if(grid[i][j]=='R'){
                si=i;
                sj=j;
              }
              if(grid[i][j]=='D'){
                di=i;
                dj=j;
              }
            }
        }

        memset(vis,false,sizeof(vis));
        bfs(si,sj);
        //path_mark
        if(vis[di][dj]){
            pair<int,int> curent;
            curent={di,dj};
            while(curent!=make_pair(si,sj))
            {
             int pi= parent[curent.first][curent.second].first;
             int pj= parent[curent.first][curent.second].second;
             if(grid[pi][pj]!='R')
             {
                grid[pi][pj]='X';
             }
             curent={pi,pj};
            }
        }
        //print
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              cout<<grid[i][j];
            }
            cout<<endl;
        }
    
        

   
    return 0;
}