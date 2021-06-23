#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 510;
const int inf = 1e8;
int n, m;
int g[N][N], dis[N];
bool vis[N];

int dijkstra()
{
    fill(dis, dis + N, inf);
    dis[1] = 0;//起点距离为0
    for (int i = 0; i < n-1;i++)//枚举中介点
    {
        int t = -1;
        for (int j = 1; j <= n;j++)
        {
            if(!vis[j]&&(t==-1||dis[t]>dis[j]))
                t = j;
        }
        if(t==-1)
            break;
        for (int j = 1; j <= n;j++)
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        vis[t] = true;
    }
    if(dis[n]==inf)
        return -1;
    return dis[n];
}
int main()
{
    scanf("%d %d", &n, &m);
    fill(g[0], g[0] + N * N, inf);//初始化边
    while(m--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    printf("%d\n", dijkstra());
    return 0;
}