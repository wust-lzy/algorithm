#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 6010;
int f[N]; //f[i]表示体积为i的最大价值
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= 0; j--)                   //枚举重量
            for (int k = 0; k <= s && k * v <= j; k++) //枚举第i个物品选0~s件
                f[j] = max(f[j], f[j - v * k] + w * k);
    }
    cout << f[m];
    return 0;
}