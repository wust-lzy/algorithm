#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second

const int N = 1010;
int n;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int g[N][N];
PII pre[N][N];
void bfs(int x, int y)
{
    memset(pre, -1, sizeof pre);
    queue<PII> q;
    q.push({x, y});
    while (!q.empty())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !g[nx][ny] && pre[nx][ny].x == -1)
            {
                q.push({nx, ny});
                pre[nx][ny] = t;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    }
    bfs(n - 1, n - 1);
    PII ed(0, 0);
    while (1)
    {
        printf("%d %d\n", ed.x, ed.y);
        if (ed.x == n - 1 && ed.y == n - 1)
            break;
        ed = pre[ed.x][ed.y];
    }
    return 0;
}