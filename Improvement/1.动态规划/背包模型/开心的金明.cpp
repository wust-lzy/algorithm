#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30, M = 30010;
int f[M];   
int n, m;
//01背包问题
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        w *= v;
        for (int j = m; j >= v; j--)
            f[j] = max(f[j - v] + w, f[j]);
    }
    cout << f[m];
    return 0;
}