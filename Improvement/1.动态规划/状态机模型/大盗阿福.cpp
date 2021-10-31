#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, inf = 1e9;
int n;
int w[N], f[N][2]; //走到第i步 选还是不选

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        f[0][0] = 0;
        f[0][1] = -inf;
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + w[i];
        }
        printf("%d\n", max(f[n][1], f[n][0]));
    }
    return 0;
}