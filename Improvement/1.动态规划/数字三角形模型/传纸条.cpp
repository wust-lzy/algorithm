#include <bits/stdc++.h>
using namespace std;
//f[k][i1][i2]表示横纵坐标和为k 第一个横坐标为i1 第二个横坐标为i2的最大路径和
const int N = 55;
int n, m, w[N][N];
int f[N * 2][N][N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    for (int k = 2; k <= n + m; k++)
    {
        for (int i1 = 1; i1 <= n; i1++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m)
                {
                    int t = w[i1][j1];
                    if (i1 != i2) //路径不重合，加上2个权值
                        t += w[i2][j2];
                    int &x = f[k][i1][i2];                    //两条路线有4种组合
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t); //下下
                    x = max(x, f[k - 1][i1 - 1][i2] + t);     //下右
                    x = max(x, f[k - 1][i1][i2 - 1] + t);     //右下
                    x = max(x, f[k - 1][i1][i2] + t);         //右右
                }
            }
        }
    }
    cout << f[n + m][n][n];
    return 0;
}