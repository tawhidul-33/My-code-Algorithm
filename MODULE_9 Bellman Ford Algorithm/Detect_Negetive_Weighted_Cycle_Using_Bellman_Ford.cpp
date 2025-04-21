// 4 4
// 0 1 5
// 1 2 3
// 2 3 2
// 3 1 -6
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
//global diclaretion
int n,e;
int dis[1005];
vector<edge> edge_list;

void Bellman_ford()
{
   for(int i=0;i<n-1;i++) //node theke akbar kom relax hobe
    {
        //relax
        for(auto ed:edge_list){
            int a,b,c;
            a=ed.a;
            b=ed.b;
            c=ed.c;
            if(dis[a]!=INT_MAX && dis[a]+c<dis[b]){
                dis[b]=dis[a]+c;
            }
        }
    } 
    //Negetive_cycle ditecded
    //jodi  uporer n-1 loop cholar por o update kora jay tar mane Negetive_Cycle ace| 
    bool Neg_cycle;
    for(auto ed:edge_list){
        int a,b,c;
        a=ed.a;
        b=ed.b;
        c=ed.c;
        if(dis[a]!=INT_MAX && dis[a]+c<dis[b]){
            Neg_cycle=true;
            break;
        }
    }
    if(Neg_cycle==true){
        cout<<"Negetive Weighted Cycle Detected";
    }else{
        for(int i=0;i<n;i++){
        cout<<i<<" min_distance -> "<<dis[i]<<endl;
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

    //intialize
    for(int i=0;i<n;i++)
    {
        dis[i]=INT_MAX;
    }
    dis[0]=0;

    //call
    Bellman_ford();
    
    return 0;
}