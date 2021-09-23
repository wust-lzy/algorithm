#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 210 , inf = 1e9;
int n,m,Q;
int dis[N][N];  //邻接矩阵

void floyd()//三层循环
{
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
    scanf("%d %d %d", &n, &m, &Q);
    fill(dis[0], dis[0] + N * N, inf);
    for (int i = 1; i <= n;i++)
        dis[i][i] = 0;
    while (m--)
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        dis[a][b] = min(dis[a][b], w);
    }
    floyd();
    while (Q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(dis[a][b]>inf/2)
            puts("impossible");
        else
            printf("%d\n", dis[a][b]);
    }
    return 0;
}