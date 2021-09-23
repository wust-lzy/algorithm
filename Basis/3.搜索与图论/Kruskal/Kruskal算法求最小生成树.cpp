#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10, inf = 1e8;
int n, m;
int father[N*2];
struct edge
{
    int a, b, w;
    bool operator<(const edge&e)const{
        return w < e.w;
    }
}edges[N];

int findfather(int x)
{
    if(father[x]==x)
        return x;
    return father[x] = findfather(father[x]);
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m;i++)
        scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].w);
    sort(edges, edges + m);
    for (int i = 1; i <= n;i++)
        father[i] = i;
    int ans = 0, cnt = 0;
    for (int i = 0; i < m;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = findfather(a), b = findfather(b);
        if(a!=b){
            father[a] = b;
            ans += w;
            cnt++;
        }
    }
    if(cnt<n-1)
        puts("impossible");
    else
        cout << ans;
    return 0;
}