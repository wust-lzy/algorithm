#include <iostream>
#include <algorithm>
using namespace std;
//为了满足字典序最小，要从后往前递推
const int N = 1010;
int n, m;
int f[N][N], v[N], w[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i + 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    }
    int j = m;
    for (int i = 1; i <= n; i++)
    {
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i])
        {
            cout << i << " ";
            j -= v[i];
        }
    }
    return 0;
}