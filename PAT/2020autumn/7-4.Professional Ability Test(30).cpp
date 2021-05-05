#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1111;
vector<int> edge[maxn];
struct node
{
    int s, d;
} stu[maxn];
vector<node> weight[maxn];
int in[maxn], du[maxn], n, m, pre[maxn], tmp, ans[maxn], tot;
queue<int> que;
void bfs()
{
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == 0)
            que.push(i);
    }
    while (!que.empty())
    {
        int hd = que.front();
        que.pop();
        ++tmp;
        for (int i = 0; i < edge[hd].size(); ++i)
        {
            int y = edge[hd][i], s = weight[hd][i].s, d = weight[hd][i].d;
            --in[y];
            if (in[y] == 0)
                que.push(y);
            s += stu[hd].s;
            d += stu[hd].d;
            if (stu[y].s == 0)
            {
                stu[y].s = s;
                stu[y].d = d;
                pre[y] = hd;
            }
            else
            {
                if (s < stu[y].s)
                {
                    stu[y].s = s;
                    stu[y].d = d;
                    pre[y] = hd;
                }
                else if (s == stu[y].s)
                {
                    if (d > stu[y].d)
                    {
                        stu[y].d = d;
                        pre[y] = hd;
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        stu[i].s = 0;
        stu[i].d = 0;
    }
    while (m--)
    {
        int t1, t2, s, d;
        scanf("%d %d %d %d", &t1, &t2, &s, &d);
        ++t1; //从1开始
        ++t2;
        edge[t1].push_back(t2);
        node cnt;
        cnt.s = s;
        cnt.d = d;
        weight[t1].push_back(cnt);
        ++in[t2];  //入度加一
        ++du[t2];  
    }
    bfs();
    if (tmp < n)
        printf("Impossible.\n");
    else
        printf("Okay.\n");
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        ++x;
        if (du[x] == 0)
            printf("You may take test %d directly.\n", x - 1);
        else if (tmp < n)
            printf("Error.\n");
        else
        {
            ans[0] = x;
            tot = 0;
            while (pre[x] > 0)
            {
                ans[++tot] = pre[x];
                x = pre[x];
            }
            for (int i = tot; i >= 1; --i)
            {
                printf("%d->", ans[i] - 1);
            }
            printf("%d\n", ans[0] - 1);
        }
    }
    return 0;
}