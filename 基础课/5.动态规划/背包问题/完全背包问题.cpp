#include <iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e3 + 10;
int v[N], w[N], f[N];//f[i]表示背包体积为i的最大价值
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n;i++){
        for (int j = m; j >= v[i];j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
    cout<<f[m];
    return 0;
}