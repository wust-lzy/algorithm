#include<bits/stdc++.h>
using namespace std;

const int N = 510, inf = 1e8;
int n, m;
int e[N][N];
int dis[N];
bool vis[N];

int prim()
{
    fill(dis, dis + N, inf);
    int ans = 0;
    for (int i = 0; i < n;i++){
        int t = -1;
        for (int j = 1; j <= n;j++){    //寻找加入集合的点
            if(!vis[j]&&(t==-1||dis[t]>dis[j]))
                t = j;
        }
        if(i&&dis[t]==inf)
            return inf;
        if (i)
            ans += dis[t];
        for (int j = 1; j <= n;j++)
            dis[j] = min(dis[j], e[t][j]);
        vis[t] = 1;//加入到集合
    }
    return ans;
}
int main()
{
    scanf("%d %d", &n, &m);
    fill(e[0], e[0] + N * N, inf);
    while(m--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = e[b][a] = min(e[a][b], c);
    }
    int ans = prim();
    if(ans==inf)
        puts("impossible");
    else
        printf("%d\n", ans);
    return 0;
}