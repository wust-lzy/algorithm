#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;
int w[N][N], f[N], path[N][N];

void dfs(int n, int m)
{
    if (!n)
        return;
    dfs(n - 1, m - path[n][m]);
    printf("%d %d\n", n, path[n][m]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k <= j; k++)
            {
                int val = f[j - k] + w[i][k];
                if (val > f[j])
                {
                    f[j] = val;
                    path[i][j] = k;
                }
            }
        }
    }

    cout << f[m] << endl;
    dfs(n, m);
    return 0;
}