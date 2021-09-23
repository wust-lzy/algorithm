#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 110;
int v[N][N], w[N][N],s[N], f[N];//f[i]表示背包体积为i的最大价值
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i];j++)
            cin >> v[i][j] >> w[i][j];
    }
    for (int i = 1; i <= n;i++)//n组
        for (int j = m; j >= 0;j--)//背包的容量
        {
            for (int k = 0; k < s[i];k++)//每个组枚举是否选
            if(v[i][k]<=j)
                f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
        }
        cout << f[m];
    return 0;
}