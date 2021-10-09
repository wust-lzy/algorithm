#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define v first
#define w second

const int N = 65, M = 32010;
pii master[N];
vector<pii> fujian[N];
int f[M];
int n, m;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int v, p, q;
        cin >> v >> p >> q;
        p *= v;
        pii t = {v, p};
        if (!q) //主件
            master[i] = t;
        else
            fujian[q].push_back(t);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k < 1 << fujian[i].size(); k++) //二进制枚举，分成2^k个组
            {
                int v = master[i].v, w = master[i].w;
                for (int x = 0; x < fujian[i].size(); x++)  //计算每一组选每个情况的v和w
                {
                    if (k >> x & 1)
                    {
                        v += fujian[i][x].v;
                        w += fujian[i][x].w;
                    }
                }
                if (v <= j)
                    f[j] = max(f[j], f[j - v] + w);
            }
        }
    }
    cout << f[m];
    return 0;
}
