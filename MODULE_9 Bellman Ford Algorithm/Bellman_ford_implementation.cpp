
// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3
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
int dis[1005];
int main()
{
    int n,e;
    cin>>n>>e;
    vector<edge> edge_list;
    while(e--)
    {
      int a,b,c;
      cin>>a>>b>>c;
      edge_list.push_back(edge(a,b,c));
      //edge_list.push_back(edge(b,a,c));//undirected

    }
    for(int i=0;i<n;i++)
    {
        dis[i]=INT_MAX;
    }
    dis[0]=0;
    //relax
    for(int i=0;i<n-1;i++) //node theke akbar kom relax hobe
    {
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
    //print
    for(int i=0;i<n;i++){
        cout<<i<<" min_distance -> "<<dis[i]<<endl;
    }
    return 0;
}

// //or function use kore
// #include<bits/stdc++.h>
// using namespace std;
// class edge
// {
//     public:
//      int a;
//      int b;
//      int c;
//      edge(int a,int b,int c)
//      {
//         this->a=a;
//         this->b=b;
//         this->c=c;
//      }
// };
// //global diclaretion
// int n,e;
// int dis[1005];
// vector<edge> edge_list;

// void Bellman_ford()
// {
//    for(int i=0;i<n-1;i++) //node theke akbar kom relax hobe
//     {
//         //relax
//         for(auto ed:edge_list){
//             int a,b,c;
//             a=ed.a;
//             b=ed.b;
//             c=ed.c;
//             if(dis[a]!=INT_MAX && dis[a]+c<dis[b]){
//                 dis[b]=dis[a]+c;
//             }
//         }
//     } 
// }
// int main()
// {
    
//     cin>>n>>e;
    
//     while(e--)
//     {
//       int a,b,c;
//       cin>>a>>b>>c;
//       edge_list.push_back(edge(a,b,c));

//     }

//     for(int i=0;i<n;i++)
//     {
//         dis[i]=INT_MAX;
//     }
//     dis[0]=0;
    
//     Bellman_ford();
//     //print
//     for(int i=0;i<n;i++){
//         cout<<i<<" min_distance -> "<<dis[i]<<endl;
//     }
//     return 0;
// }