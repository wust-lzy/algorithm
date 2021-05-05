#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int dp[8][8];
int main()
{
    for (int i = 1; i <= 7; i++)
        dp[i][0] = 1;
    int sum = 0;
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 8 - i; j++)
        {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] += dp[i][j - 1];
        }
        sum += dp[i][8 - i];
    }
    cout << sum << endl;
    return 0;
}
