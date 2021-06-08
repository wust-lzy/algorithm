#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int a[N], n, t, k;
int main()
{
    cin >> t;
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n;i++)
            scanf("%d", &a[i]);
        sort(a, a + n, greater<int>());
        ll ans = 0;
        for (int i = 0; i < k + 1;i++)
            ans += a[i];
        cout << ans << endl;
    }
    return 0;
}