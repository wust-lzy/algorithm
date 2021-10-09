#include <iostream>
#include <cstring>
#include <algorithm>
//完全背包求方案数
using namespace std;
const int N = 1010;
int f[N];
int w[4] = {10, 20, 50, 100};
int main()
{
    int m;
    cin >> m;
    f[0] = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = w[i]; j <=m; j++)
            f[j] += f[j - w[i]];
    }
    cout << f[m];
    return 0;
}