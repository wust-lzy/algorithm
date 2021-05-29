#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N], vis[N];
int main()
{
    ll ans = 0;
    int n, k, i;
    cin >> n >> k;
    for (i = 0; i < n;i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n;i++)
    {
        scanf("%d", &vis[i]);
        if(vis[i])
            ans += a[i];
    }
    ll sum = 0, temp = 0;
    for (i = 0; i < n;i++)
    {
        if(!vis[i])
            temp += a[i];
        if(i>=k&&!vis[i-k])
            temp -= a[i - k];
        sum = max(temp, sum);
    }
    cout << ans+sum;
    return 0;
}