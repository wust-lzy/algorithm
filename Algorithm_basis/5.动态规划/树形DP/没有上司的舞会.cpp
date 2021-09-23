#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 6010;
//f[u][0]所有以u为根的子树中选择，并且不选u这个点的方案
//f[u][1]所有以u为根的子树中选择，并且选u这个点的方案
int f[N][2];
int n, happy[N];
bool has_father[N];
int h[N], e[N], ne[N], idx; //邻接表

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    f[u][1] = happy[u];
    for (int i = h[u]; i != -1;i=ne[i])
    {
        int j = e[i];//u的儿子
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &happy[i]);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n-1;i++)
    {
        int a, b;//a是b的后代
        scanf("%d %d", &a, &b);
        has_father[a] = true;
        add(b, a);//把a连到b后面
    }
    int root = 1;//找到根结点
    while(has_father[root])
        root++;
    dfs(root);
    printf("%d\n", max(f[root][0], f[root][1]));
    return 0;
}