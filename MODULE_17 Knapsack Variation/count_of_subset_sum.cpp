// 4
// 1 2 4 6
// 7
#include <bits/stdc++.h>
using namespace std;
int val[105];
int dp[105][105];
int sub_set(int i, int sum) // O(N*sum)
{
    // base case
    if (i < 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }

    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    if (val[i] <= sum)
    {
        int op1 = sub_set(i - 1, sum - val[i]); // int op1=sub_set(i,sum-val[i]); //for unbounded
        int op2 = sub_set(i - 1, sum);
        dp[i][sum] = op1 + op2;
        return dp[i][sum];
    }
    else
    {
        dp[i][sum] = sub_set(i - 1, sum);
        return dp[i][sum];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int sum;
    cin >> sum;

    memset(dp, -1, sizeof(dp));

    cout << "Total way for Subset sum creat = " << sub_set(n - 1, sum);

    return 0;
}
