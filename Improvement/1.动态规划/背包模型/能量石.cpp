#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110, M = 10010;
struct Stone
{
    int s, e, l;
    bool operator<(const Stone &w) const
    {
        return s * w.l < l * w.s;
    }
} stones[N];
int f[M];
int main()
{
    int T;
    cin >> T;
    int kase = 0;
    while (T--)
    {
        int m = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> stones[i].s >> stones[i].e >> stones[i].l;
            m += stones[i].s;
        }
        sort(stones + 1, stones + 1 + n); //贪心 按照单位时间流逝最慢的能量石排序
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) // 01背包求解
        {
            int e = stones[i].e, s = stones[i].s, l = stones[i].l;
            for (int j = m; j >= s; j--)
                f[j] = max(f[j], f[j - s] + max(0, e - l * (j - s)));
        }
        int res = *max_element(f, f + m + 1);
        printf("Case #%d: %d\n", ++kase, res);
    }
    return 0;
}
