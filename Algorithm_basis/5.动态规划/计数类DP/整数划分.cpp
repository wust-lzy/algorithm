#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1010, mod = 1e9 + 7;//体积为n，物品为1，2，3...,n的方案数
int f[N];//容量为n时的方案数
int main()
{
    int n;
    cin >> n;
    f[0] = 1;// 容量为0时，前 i 个物品全不选也是一种方案
    for (int i = 1; i <= n;i++)
        for (int j = i; j <= n;j++)
            f[j] = (f[j] + f[j - i]) % mod;
    cout << f[n];
    return 0;
}