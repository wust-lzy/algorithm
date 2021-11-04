#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;
int n, m;
int g[N];
vector<int> state, head[M];
int f[N][M]; // f[i][s]表示所有摆完前i行，第i行状态是s的方案数

bool check(int st)
{
    for (int i = 0; i < m; i++)
    {
        if ((st >> i & 1) && (st >> (i + 1) & 1))
            return 0;
    }
    return 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            g[i] += !t << j;
        }
    }
    for (int i = 0; i < 1 << m; i++)
    {
        if (check(i))
            state.push_back(i);
    }
    for (int i = 0; i < (int)state.size(); i++)
    {
        for (int j = 0; j < (int)state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0)
                head[i].push_back(j);
        }
    }
    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int a = 0; a < state.size(); a++)
        {
            for (int b : head[a])
            {
                if (g[i] & state[a])
                    continue;
                f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
            }
        }
    }
    cout << f[n + 1][0] << endl;
    return 0;
}