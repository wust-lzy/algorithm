#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n;
int q[N], up[N], down[N];//up[i]记录每个上升子序列的末尾值
int ans;//贪心+暴搜 看每个数能不能放到一个序列的后面，不能就开一个序列
void dfs(int u, int su, int sd)//暴搜所有的情况，分别放到上升和下降的序列中
{
    if (su + sd >= ans)
        return;
    if (u == n)
    {
        ans = su + sd;
        return;
    }
    //情况1：将当前数放到上升子序列中
    int k = 0;
    while (k < su && up[k] >= q[u])
        k++;
    int t = up[k];
    up[k] = q[u];
    if (k < su)
        dfs(u + 1, su, sd);
    else
        dfs(u + 1, su + 1, sd);
    up[k] = t;

    //情况2 将当前数放到下降子序列中
    k = 0;
    while (k < sd && down[k] <= q[u])
        k++;
    t = down[k];
    down[k] = q[u];
    if (k < sd)
        dfs(u + 1, su, sd);
    else
        dfs(u + 1, su, sd + 1);
    down[k] = t;
}
int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
            cin >> q[i];
        ans = n;
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}