#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        if (s == 0)//完全背包
        {
            for (int j = v; j <= m; j++)
                f[j] = max(f[j], f[j - v] + w);
        }
        else
        {
            if (s == -1)//01背包
                s = 1;
            for (int k = 1; k <= s; k *= 2)//二进制优化多重背包
            {
                for (int j = m; j >= k * v; j--)
                    f[j] = max(f[j], f[j - k * v] + k * w);
                s -= k;
            }
            if (s)
                for (int j = m; j >= v * s; j--)
                    f[j] = max(f[j], f[j - s * v] + s * w);
        }
    }
    cout << f[m];
    return 0;
}