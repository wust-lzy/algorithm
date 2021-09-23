#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 510, M = 10010;
const int inf = 1e8;
int n, m, k;
int dis[N], backup[N];// dist[x]存储1到x的最短路距离
struct edge // 边，a表示出点，b表示入点，w表示边的权重
{
    int a, b, w;
}edges[M];
// 求1到n的最短路距离，如果无法从1走到n，则返回-1。
int bellman_ford()
{
    fill(dis, dis + N, inf);
    dis[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dis, sizeof dis);
        for (int j = 0; j < m;j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dis[b] = min(dis[b], backup[a] + w);
        }
    }
    if(dis[n]>inf/2)
        return -2;
    return dis[n];
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m;i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    int ans = bellman_ford();
    if(ans==-2)
        puts("impossible");
    else
        cout << ans;
    return 0;
}