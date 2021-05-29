#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int mp[105][105],a[105][105];//mp记录路径长度
int r, c, i, j;

int dfs(int x,int y)
{
    if(mp[x][y])
        return mp[x][y];
    mp[x][y] = 1;
    for (int i = 0; i < 4;i++)
    {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx>=0&&dx<r&&dy>=0&&dy<c&&a[dx][dy]<a[x][y])
        {
            dfs(dx, dy);
            mp[x][y] = max(mp[x][y], mp[dx][dy] + 1);
        }
    }
    return mp[x][y];
}
int main()
{
    int ans = 0;
    memset(mp, 0, sizeof(mp));
    cin >> r >> c;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            cin >> a[i][j];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            ans = max(dfs(i, j), ans);
        }
    cout << ans;
    return 0;
}