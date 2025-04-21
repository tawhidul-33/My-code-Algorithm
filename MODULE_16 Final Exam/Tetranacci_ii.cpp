//Note : You must solve this problem using Loop. (Bottom up)
//4
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    long long int tetranacci[n+1];
    tetranacci[0]=0;
    tetranacci[1]=1;
    tetranacci[2]=1;
    tetranacci[3]=2;
    for(int i=4;i<=n;i++)
    {
        tetranacci[i]=tetranacci[i-1]+tetranacci[i-2]+tetranacci[i-3]+tetranacci[i-4];
    }
    cout<<tetranacci[n]<<endl;
    return 0;
}

