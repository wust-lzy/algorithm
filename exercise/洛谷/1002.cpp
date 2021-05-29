#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mx, my, i, j, bx, by;
bool vis[25][25];
ll f[25][25];
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
const int dir[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int main()
{
    memset(vis, 0, sizeof(vis));
    cin >> bx >> by >> mx >> my;
    bx += 2;
    by += 2;
    mx += 2;
    my += 2;
    f[2][2] = 1;
    vis[mx][my] = 1;//马的位置标记不能走
    for (i = 0; i < 8;i++)
    {
        vis[dir[i][0]+mx][dir[i][1]+my] = 1;
    }
    for (i = 2; i <= bx;i++)
        for (j = 2; j <= by;j++)
        {
            if(!vis[i][j])
                f[i][j] = max(f[i][j], f[i - 1][j] + f[i][j - 1]);   
        }
    cout << f[bx][by];
    return 0;
}