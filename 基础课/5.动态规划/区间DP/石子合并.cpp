#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 310;
int f[N][N];//所有将第i到j堆石子合并成1堆石子的操作方式
int s[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)//前缀和
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for (int len = 2; len <= n;len++)//枚举长度
        for (int i = 1; i + len - 1 <= n;i++)//起点
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e8;
            for (int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    cout << f[1][n];
    return 0;
}