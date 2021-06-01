#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
const ll N = 2e5 + 5;
ll a[N];
ll s[N];
bool check(ll mid)
{
    ll res = 0;
    for (int i = n / 2; i < n;i++){
        if(a[i]<mid)
            res += mid - a[i];
        else
            break;
    }
    return res <= k;
}
int main()
{ 
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    s[0] = a[0];
    for (ll i = 1; i < n; i++)
        s[i] = a[i] + s[i - 1];
    ll l = 0, r = 2e9;
    while (l < r)
    {
        ll mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%lld", l);
}