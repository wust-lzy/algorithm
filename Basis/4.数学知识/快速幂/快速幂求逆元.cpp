#include <iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;

ll quick_pow(ll a,ll b,ll mod)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll a, mod;
        scanf("%lld %lld", &a, &mod);
        if(a%mod==0)
            puts("impossible");
        else
            printf("%lld\n", quick_pow(a, mod - 2, mod));
    }
    return 0;
}