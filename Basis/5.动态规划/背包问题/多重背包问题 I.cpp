#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e3 + 10;
int v[N], w[N],s[N], f[N][N];//f[i][j]表示前i件物品背包体积为j的最大价值
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++)//枚举重量
            for (int k = 0; k <= s[i]&& k * v[i] <= j;k++)//枚举第i个物品选0~S[i]件
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
    }
    cout<<f[n][m];
    return 0;
}