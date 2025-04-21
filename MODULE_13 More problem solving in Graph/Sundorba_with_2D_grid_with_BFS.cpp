// Sample Input
// 5
// S P P P P
// T P T P P
// T P P P P
// P T E T T
// P T P T T

#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
int n;

bool valid(int i,int j){
    if(i<0||i>=n||j<0||j>=n){
        return false;
    }
    return true;
}

vector<pair<int,int> >mov;//={{-1,0},{1,0},{0,-1},{0,1}};
void bfs(int si,int sj)
{
    queue<pair<int,int> >q;
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
            if(valid(ci,cj)==true &&vis[ci][cj]==false  && grid[ci][cj]!='T')
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
    mov.push_back({-1,0});//={{-1,0},{1,0},{0,-1},{0,1}};uprer aitar poriborte
    mov.push_back({1,0});
    mov.push_back({0,-1});
    mov.push_back({0,1});

 while(cin>>n)
 {
    int si,sj,di,dj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='S')
            {
              si=i;
              sj=j;
            }
            if(grid[i][j]=='E')
            {
              di=i;
              dj=j;
            }
        }
    }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    
    cin>>si>>sj>>di>>dj;
    bfs(si,sj);
    
    //short distance
    cout<<level[di][dj]<<endl;
 }
    

    return 0;
}
