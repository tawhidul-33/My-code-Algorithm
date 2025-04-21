// 4   /-test_case

// 8 8 /- Size n,m
// 0 0 /-source si,sj
// 7 7 /-destination di,dj

// 5 6
// 0 1
// 0 1

// 4 4
// 0 0
// 0 1

// 2 2
// 0 0
// 0 1
#include<bits/stdc++.h>
using namespace std;
bool vis[105][105];
int level[105][105];
int n,m;
bool valid(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m)
        return false;
    else
        return true;
}
vector<pair<int,int>>mov={{2,-1},{2,1},{-2,-1},{-2,1},{1,-2},{1,2},{-1,-2},{-1,2}};
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
        

        //child push kora
        for(int i=0;i<8;i++)
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
    int t;
    cin>>t;
    while(t--)
    {
        
        cin>>n>>m;
        int si,sj,di,dj;
        cin>>si>>sj>>di>>dj;

        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        bfs(si,sj);

        if(vis[di][dj]==true){
            cout<<level[di][dj]<<endl;
        }else{
            cout<<-1<<endl;
        }
        

    }
    return 0;
}