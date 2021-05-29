#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005][1005];
int a[1005][1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        for (int j = 0; j <i+1;j++)
        {
            cin >> a[i][j];
            dp[i][j] = a[i][j];
        }
    for (int i = n - 2; i >= 0;i--)
        for (int j = 0; j < i + 1;j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
    cout << dp[0][0];
    return 0;
}