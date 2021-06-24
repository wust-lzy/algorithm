#include <iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e6 + 10;
const int inf = 1e8;
int n, m;
int h[N], w[N], e[N], ne[N], idx;//邻接表存储所有边
int dis[N]; //存储所有点到1号点的距离
bool vis[N];//每个点是否已经选过

void add(int a,int b,int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
// 求1号点到n号点的最短距离，如果不存在，则返回-1
int spfa()
{
    fill(dis, dis + N, inf);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        vis[t] = false;
        for (int i = h[t]; i != -1;i=ne[i])
        {
            int j = e[i];
            if(dis[j]>dis[t]+w[i])
            {
                dis[j] = dis[t] + w[i];
                if(!vis[j])
                {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }
    if(dis[n]==inf)
        return -1;
    return dis[n];
}
int main()
{
    scanf("%d %d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    int ans = spfa();
    if(ans==-1)
        puts("impossible");
    else
        printf("%d\n", ans);
    return 0;
}