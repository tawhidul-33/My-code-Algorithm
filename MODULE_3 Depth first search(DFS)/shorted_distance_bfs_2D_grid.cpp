// 3 4
// ....
// ....
// ....
// 1 2 /-> si,,sj
// 2 0 /-> di,,dj
#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
int n,m;

bool valid(int i,int j){
    if(i<0||i>=n||j<0||j>=m){
        return false;
    }
    return true;
}

vector<pair<int,int>>mov={{-1,0},{1,0},{0,-1},{0,1}};
void bfs(int si,int sj)
{
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj]=true;
    level[si][sj]=0;
    while(!q.empty())
    {
        //ber kore ana
        pair<int,int>par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        
        //oi node niye kaj kora
        //cout<<par_i<<" "<<par_j<<endl;

        //child push kora
        for(int i=0;i<4;i++)
        {
            int ci=par_i+ mov[i].first;
            int cj=par_j+ mov[i].second;
            if(vis[ci][cj]==false && valid(ci,cj)==true)
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                level[ci][cj]=level[par_i][par_j]+1;
            }
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
    memset(level,-1,sizeof(level));
    int si,sj,di,dj;//si== src i,,sj==src j,,di==destination
    cin>>si>>sj>>di>>dj;
    bfs(si,sj);
    
    //short distance
    cout<<level[di][dj]<<endl;
    return 0;
}