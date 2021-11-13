#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1010;
typedef pair<int, int> pii;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;
char g[N][N];
bool vis[N][N];
int dis[N][N];
void bfs()
{
    queue<pii> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '1')
            {
                q.push(pii(i, j));
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        pii t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
            {
                dis[nx][ny] = dis[t.x][t.y] + 1;
                vis[nx][ny] = 1;
                q.push(pii(nx, ny));
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    bfs();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}