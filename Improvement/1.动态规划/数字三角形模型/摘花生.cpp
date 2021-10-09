#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int a[N][N], f[N][N];
int t, n, m;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
            }
        }
        cout << f[n][m] << endl;
    }
    return 0;
}