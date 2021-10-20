#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110, M = 110;
int h[N], e[M], ne[M], idx;
int v[N], w[N], f[N][N];

int n, m;

void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int son = e[i];
        dfs(son);

        //分组背包
        for (int j = m - v[u]; j >= 0; j--)
        {
            for (int k = 0; k <= j; k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
        }
    }
    //将物品u加进去
    for (int i = m; i >= v[u]; i--)
        f[u][i] = f[u][i - v[u]] + w[u];
    for (int i = 0; i < v[u]; i++)
        f[u][i] = 0;
}
int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);
    int root;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1)
            root = i;
        else
            add(p, i);
    }
    dfs(root);
    cout << f[root][m];
    return 0;
}