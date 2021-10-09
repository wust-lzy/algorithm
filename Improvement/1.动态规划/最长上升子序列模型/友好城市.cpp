#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 5010;
typedef pair<int, int> pii;
pii q[N];
int f[N], n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
        scanf("%d %d", &q[i].first, &q[i].second);
    sort(q, q + n);
    int ans = 0;
    for (int i = 0; i < n;i++){//从南到北 连起来的一条路径是上升的序列
        f[i] = 1;
        for (int j = 0; j < i;j++)
        if(q[i].second>q[j].second)
            f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}