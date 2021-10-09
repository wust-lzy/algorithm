//f[i,j,k] 从前i个物品中选，总体积不超过j，重量不超过k的最大值
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int f[N][N]; //01背包优化
int n, V, M;

int main()
{
    cin >> n >> V >> M;
    for (int i = 0; i < n; i++)
    {
        int v, m, w;
        cin >> v >> m >> w;
        for (int j = V; j >= v; j--)
        {
            for (int k = M; k >= m; k--)
                f[j][k] = max(f[j][k], f[j - v][k - m] + w);
        }
    }
    cout << f[V][M];
    return 0;
}