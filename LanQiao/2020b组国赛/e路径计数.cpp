#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1}}; //上右下左
int vis[10][10];
int cnt=0;

void dfs(int x, int y, int step)
{
    if (step > 12)
        return;
    if (x == 0 && y == 0 && step >2)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int a = x + dir[i][0];
        int b = y + dir[i][1];
        if (a >=0  && a < 6 && b >=0  && b < 6 && !vis[a][b])
        {
            vis[a][b] = 1;
            dfs(a, b, step + 1);
            vis[a][b] = 0;
        }
    }
}

int main()
{
    dfs(0, 0, 0);
    cout << cnt;
    return 0;
}
