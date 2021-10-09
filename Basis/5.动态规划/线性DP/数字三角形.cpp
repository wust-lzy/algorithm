#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 510;
const int inf = 1e7;
int a[N][N], dp[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= i;j++)
            cin >> a[i][j];
    fill(dp[0], dp[0] + N * N, -inf);
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n;i++)
        for (int j = 1; j <= i;j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
    int maxn = -inf;
    for (int i = 1; i <= n;i++)
        maxn = max(maxn, dp[n][i]);
    cout << maxn;

    return 0;
}