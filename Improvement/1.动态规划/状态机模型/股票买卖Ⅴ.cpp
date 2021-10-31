#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, inf = 1e9;

int n;
int w[N], f[N][3]; //表示第i天手中有货，第一天无货，>=2天无货的状态

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    f[0][0] = f[0][1] = -inf;
    f[0][2] = 0; //初始化第0天为>=2天无货

    for (int i = 1; i <= n; i++) //状态机转移方程
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
        f[i][1] = f[i - 1][0] + w[i];
        f[i][2] = max(f[i - 1][2], f[i - 1][1]);
    }
    cout << max(f[n][1], f[n][2]);
    return 0;
}