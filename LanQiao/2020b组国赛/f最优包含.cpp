#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005][1005];
#define INF 0x3f3f3f3f
int main()
{
    string s, t;
    cin >> s >> t;
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                if (dp[i - 1][j - 1] == INF)
                    dp[i][j] = min(dp[i][j], 0);
                else
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            else
            {
                if (dp[i - 1][j - 1] == INF)
                    dp[i][j] = min(1, dp[i - 1][j]);
                else
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
            }
        }
    }
    cout << dp[s.length()][t.length()];
    return 0;
}