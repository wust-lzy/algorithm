#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 110, inf = 1e9;
int n, m;
int f[N][M][2], w[N];//表示前i天，交易数为j，是否持有股票的最大收益

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i++)
        f[i][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);//卖出和不卖出，求max
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);//买入和不买入，求max
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        ans = max(ans, f[n][i][0]);
    cout << ans;
    return 0;
}