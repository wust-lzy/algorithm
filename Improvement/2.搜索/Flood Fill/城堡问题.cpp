#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 55, M = N * N;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; //按照西北东南的方向
int n, m;
int g[N][N];

bool vis[N][N];
int bfs(int x, int y)
{
    queue<PII> q;
    q.push({x, y});
    int ans = 0;
    while (!q.empty())
    {
        ans++;
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
            {
                if (g[t.x][t.y] >> i & 1)//判断有没有墙
                    continue;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    int cnt = 0, area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                vis[i][j] = 1;
                area = max(area, bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << endl //求最大连通块
         << area;
    return 0;
}