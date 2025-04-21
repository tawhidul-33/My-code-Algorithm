// 3
// 2 9 13
// 4
// 3 5 7 8
// 2ta sorted arry ke ,,sorted way te jora diya ke conquer bole
#include <bits/stdc++.h>
using namespace std;
int main()
{  
    //O(N)
    // first sorted arry input
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // secund sorted arry input
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    // conquer
    int c[n + m];
    int i = 0, j = 0, curent = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            c[curent] = a[i];
            i++;
            curent++;
        }
        else
        {
            c[curent] = b[j];
            j++;
            curent++;
        }
    }
    // uprer looper khetre akti looper bayre gele o
    //  arekte ongso theke jay sei khetre nicher jekno akti ongse kaj korbe
    while (i < n)
    {
        c[curent] = a[i];
        i++;
        curent++;
    }
    while (j < m)
    {
        c[curent] = b[j];
        j++;
        curent++;
    }
    //print
    for(int i=0;i<n+m;i++)
    {
        cout<<c[i]<<" ";
    }

    return 0;
}
