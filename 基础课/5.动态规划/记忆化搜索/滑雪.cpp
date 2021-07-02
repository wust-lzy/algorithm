#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 310;
int f[N][N], h[N][N];
int n, m;
const int go[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int dp(int x,int y)
{
    if(f[x][y]!=-1)
        return f[x][y];
    f[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int dx = x + go[i][0], dy = y + go[i][1];
        if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&h[dx][dy]<h[x][y])//界内且由高往低
            f[x][y] = max(f[x][y], dp(dx, dy) + 1);
    }
    return f[x][y];
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n;i++)//输入高度
        for (int j = 1; j <= m;j++)
            scanf("%d", &h[i][j]);
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            res = max(res, dp(i, j));
    cout << res;
    return 0;
}