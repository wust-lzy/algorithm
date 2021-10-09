#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e3 + 10;
int n, m;
int f[N];
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++) //01背包
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--)
            f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m];
    return 0;
}