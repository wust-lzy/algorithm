#include <iostream>
#include <cstring>
#include <algorithm>
//01背包求方案数
using namespace std;
const int N = 10010;
int f[N];

int main()
{
    int n, m;
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        for (int j = m; j >= v; j--)
            f[j] += f[j - v];
    }
    cout << f[m];
    return 0;
}