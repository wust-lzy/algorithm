#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int n;
int a[N];
int tr[N];
int Greater[N], lower[N];

int lowbit(int x)
{
    return x & -x;
}

void update(int x, int c) // 位置x加c
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int query(int x) // 返回前x个数的和
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        int y = a[i];
        Greater[i] = query(n) - query(y);
        lower[i] = query(y - 1);
        update(y, 1);
    }
    memset(tr, 0, sizeof tr);
    LL res1 = 0, res2 = 0;
    for (int i = n; i >= 1; i--)
    {
        int y = a[i];
        res1 += Greater[i] * (LL)(query(n) - query(y));
        res2 += lower[i] * (LL)(query(y - 1));
        update(y, 1);
    }
    printf("%lld %lld\n", res1, res2);
    return 0;
}