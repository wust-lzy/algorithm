#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
//cnt[i]代表调到i分钟最少要多少次，vis[i]代表i分钟是否讨论过
int cnt[N], vis[N];
int n, k;
void bfs()
{
    //队列，first记录第几分钟，second记录这一分钟调了多少次
    queue<pair<int, int> > q;
    vis[0] = 1;
    q.push(make_pair(0, 0));//0分钟不用调
    int go;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        //走一分钟
        go = (p.first + 1) % n;
        if (!vis[go])
        {
            vis[go] = 1;
            cnt[go] = p.second + 1;
            q.push(make_pair(go, p.second + 1));
        }
        //走k分钟
        go = (p.first + k) % n;
        if (!vis[go])
        {
            vis[go] = 1;
            cnt[go] = p.second + 1;
            q.push(make_pair(go, p.second + 1));
        }
    }
}
int main()
{
    int ans = -1;
    cin >> n >> k;
    bfs();
    for (int i = 0; i < n; i++)//求最大值
        ans = max(ans, cnt[i]);
    cout << ans;
    return 0;
}