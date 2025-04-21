// 3
// 121
// 39
// 123456
#include<bits/stdc++.h>
using namespace std;
void recurtion(int n)
    {
        if(n<10)
        {
            cout<<n<<" ";
            return;
        }
        recurtion(n/10);
        cout<<n%10<<" ";
    }
int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
         recurtion(n);
         cout<<endl;

    }
    return 0;
}