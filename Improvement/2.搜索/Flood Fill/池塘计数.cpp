#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int N = 1010, go[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
char g[N][N];
int n, m;

void bfs(int x, int y)
{
    queue<pii> q;
    q.push(pii(x, y));
    g[x][y] = '.';
    while (!q.empty())
    {
        pii t = q.front();
        q.pop();
        x = t.first, y = t.second;
        for (int i = 0; i < 8; i++)
        {
            int dx = x + go[i][0];
            int dy = y + go[i][1];
            if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && g[dx][dy] == 'W')
            {
                g[dx][dy] = '.';
                q.push(pii(dx, dy));
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> g[i] + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (g[i][j] == 'W')
            {
                ans++;
                bfs(i, j);
            }
    }
    cout << ans;
    return 0;
}