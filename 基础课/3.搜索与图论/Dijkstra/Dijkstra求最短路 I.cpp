#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 510;
const int inf = 1e8;
int n, m;
int e[N][N], dis[N];
bool vis[N];

int dijkstra()
{
    fill(dis, dis + N, inf);
    dis[1] = 0;//起点距离为0
    for (int i = 0; i < n-1;i++)//枚举中介点
    {
        int u = -1;
        for (int j = 1; j <= n;j++)
        {
            if(!vis[j]&&(u==-1||dis[u]>dis[j]))
                u = j;
        }
        if(u==-1)
            break;
        vis[u] = true;
        for (int v = 1; v <= n;v++)
            dis[v] = min(dis[v], dis[u] + e[u][v]);
        
    }
    if(dis[n]==inf)
        return -1;
    return dis[n];
}
int main()
{
    scanf("%d %d", &n, &m);
    fill(e[0], e[0] + N * N, inf);//初始化边
    while(m--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = min(e[a][b], c);
    }
    printf("%d\n", dijkstra());
    return 0;
}