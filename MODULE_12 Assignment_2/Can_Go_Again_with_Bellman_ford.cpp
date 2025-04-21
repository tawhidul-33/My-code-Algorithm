// 5 7
// 1 2 10
// 1 3 -2
// 3 2 1
// 2 4 7
// 3 4 -3
// 4 5 5
// 2 5 2
// 5
// 5
// 1
// 2
// 3
// 4
// 5
#include<bits/stdc++.h>
using namespace std;
class edge
{
    public:
     int a;
     int b;
     int c;
     edge(int a,int b,int c)
     {
        this->a=a;
        this->b=b;
        this->c=c;
     }
};
vector<edge>edge_list;
long long int dis[1005];
int n,e;
bool cycle=false;
void Bellman_ford()
{
    for(int i=0;i<n-1;i++)
    {
        for(auto ed : edge_list)
        {
            int a=ed.a;
            int b=ed.b;
            int c=ed.c;
            if(dis[a]!=LLONG_MAX && dis[a]+c<dis[b])
            {
                dis[b]=dis[a]+c;
            }
        }
    }
   //negetive cycle ditected
   
        for(auto ed : edge_list)
        {
            int a=ed.a;
            int b=ed.b;
            int c=ed.c;
            if(dis[a]!=LLONG_MAX && dis[a]+c<dis[b])
            {
               cycle=true; 
            
            }
        }
}
int main()
{
    
    cin>>n>>e;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge_list.push_back(edge(a,b,c));  
    }
    int src;
    cin>>src;

    //intialize
    for(int i=1;i<=n;i++)
    {
        dis[i]=LLONG_MAX;
    }
    dis[src]=0;
    Bellman_ford();
    if(cycle==true)
    {
        cout<<"Negative Cycle Detected"<<endl;
    }
    else{
        int q;
        cin>>q;
        while(q--)
        {
            int qn;
            cin>>qn;
            if(dis[qn]==LLONG_MAX)
            {
                cout<<"Not Possible"<<endl;
            }else{
                cout<<dis[qn]<<endl;
            }
        }
    }


    return 0;
}