#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 1010;
int n;
int h[N][N];
bool vis[N][N];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(int x, int y, bool &high, bool &low)
{
    queue<PII> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (h[nx][ny] != h[x][y])
                {
                    if (h[nx][ny] > h[x][y])
                        high = 1;
                    else
                        low = 1;
                }
                else if (!vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    q.push(PII(nx, ny));
                }
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
        {
            scanf("%d", &h[i][j]);
        }
    }
    int peak = 0, valley = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                bool has_higher = 0, has_lower = 0;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher)
                    peak++;
                if (!has_lower)
                    valley++;
            }
        }
    }
    cout << peak << " " << valley;
    return 0;
}