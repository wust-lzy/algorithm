#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//f[i][j]表示已经走过的点的集合i，移动到j
const int N = 20, M = 1 << N;
int n, w[N][N];
int f[M][N];
const int inf = 1e8;
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            scanf("%d", &w[i][j]);
    fill(f[0], f[0] + M * N, inf);
    f[1][0] = 0;//从0这个点走到0 花费1
    for (int i = 0; i < 1 << n; i++)//二进制枚举所有走过点的集合
        for (int j = 0; j < n;j++)
        if(i>>j&1)
            for (int k = 0; k < n;k++)//k是中间点 看是否去掉j这个点 从k走是不是花费更小
            if((i-(1<<j))>>k&1)
                f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
    cout << f[(1 << n) - 1][n - 1];
    return 0;
}