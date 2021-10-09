#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 25, M = 80, inf = 1e8;
int f[N][M];
using namespace std;

int m, n, k;

int main()
{
    fill(f[0], f[0] + N * M, inf);
    cin >> n >> m;
    cin >> k;
    f[0][0] = 0;
    while (k--)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for (int i = n; i >= 0; i--)
        {
            for (int j = m; j >= 0; j--)
                f[i][j] = min(f[i][j], f[max(0, i - v1)][max(0, j - v2)] + w);
        }
    }
    cout << f[n][m];
    return 0;
}