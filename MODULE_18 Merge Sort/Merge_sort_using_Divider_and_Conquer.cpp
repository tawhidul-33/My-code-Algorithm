#include <bits/stdc++.h>
using namespace std;
//O(NlogN)
void conquer(int ar[], int l, int mid, int r)
{
    // vag kore left arry kora
    int n = mid - l + 1;
    int L[n];
    int k = l;
    for (int i = 0; i < n; i++)
    {
        L[i] = ar[k];
        k++;
    }
    // vag kore right arry kora
    int m = r - mid;
    int R[m];
    k = mid + 1;
    for (int i = 0; i < m; i++)
    {
        R[i] = ar[k];
        k++;
    }
    // conquer
    int i = 0, j = 0, curent = l;
    while (i < n && j < m)
    {
        if (L[i] < R[j])
        {
            ar[curent] = L[i];
            i++;
            curent++;
        }
        else
        {
            ar[curent] = R[j];
            j++;
            curent++;
        }
    }
    // uprer looper khetre akti looper bayre gele o
    //  arekte ongso theke jay sei khetre nicher jekno akti ongse kaj korbe
    while (i < n)
    {
        ar[curent] = L[i];
        i++;
        curent++;
    }
    while (j < m)
    {
        ar[curent] = R[j];
        j++;
        curent++;
    }
}
void divide(int ar[], int l, int r)
{
    // base case
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    divide(ar, l, mid);
    divide(ar, mid + 1, r);

    conquer(ar, l, mid, r);
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    divide(ar, 0, n - 1);
    // print
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}
