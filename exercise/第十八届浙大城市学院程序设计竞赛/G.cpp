#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
const int inf = 1e7;
int a[maxn], b[maxn];
int pos[maxn];
int cnt[maxn];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <=n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", b + i);
        pos[b[i]] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        int x = a[i];
        if(pos[x]>i)
            continue;
        cnt[i - pos[x] + 1]++;
    }
    int ans = inf;
    for (int i = 1; i <= n;i++)
    {
        ans = min(ans, n - cnt[i]);
    }
    printf("%d\n",ans);
}
int main()
{
    run();
    return 0;
}

