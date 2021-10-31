#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 12, M = 1 << 10, K = 110;
int n, m;
vector<int> vis;
int cnt[M];
vector<int> head[M];
int f[N][K][M];

bool check(int st)
{
    for (int i = 0; i < n; i++)
    {
        if ((st >> i & 1) && (st >> i + 1 & 1))
            return 0;
    }
    return 1;
}
int count(int st)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += st >> i & 1;
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < 1 << n; i++)
    {
        if (check(i))
        {
            vis.push_back(i);
            cnt[i] = count(i);
        }
    }
    for (int i = 0; i < vis.size(); i++)
    {
        for (int j = 0; j < vis.size(); j++)
        {
            int a = vis[i], b = vis[j];
            if ((a & b) == 0 && check(a | b))
            {
                head[i].push_back(j);
            }
        }
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int a = 0; a < vis.size(); a++)
            {
                for (int b : head[a])
                {
                    int c = cnt[vis[a]];
                    if (j >= c)
                    {
                        f[i][j][a] += f[i - 1][j - c][b];
                    }
                }
            }
        }
    }
    cout << f[n + 1][m][0] << endl;
    return 0;
}