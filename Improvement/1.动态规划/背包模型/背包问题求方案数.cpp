#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;
int f[N], g[N]; //体积恰好是j的方案数
int n, m;
int main()
{
    cin >> n >> m;
    f[0] = 0;
    g[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--)
        {
            int maxv = max(f[j], f[j - v] + w);
            int cnt = 0;
            if (maxv == f[j])
                cnt = g[j];
            if (maxv == f[j - v] + w)
                cnt = (cnt + g[j - v]) % mod;
            f[j] = maxv;
            g[j] = cnt;
        }
    }
    int maxv = *max_element(f + 1, f + 1 + m); //找到最大值
    int cnt = 0;
    for (int i = 0; i <= m; i++)
    {
        if (f[i] == f[m])
            cnt = (cnt + g[i]) % mod;
    }
    cout << cnt;
    return 0;
}