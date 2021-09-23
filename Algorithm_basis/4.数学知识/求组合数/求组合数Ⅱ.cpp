#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5+10,mod=1e9+7;
typedef long long ll;

int fact[N], infact[N];

ll quick_pow(ll a,ll k,ll p){
    ll ans = 1;
    while(k)
    {
        if(k&1)
            ans = ans * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return ans;
}
int main()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N;i++){
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i]=(ll) infact[i - 1] * quick_pow(i, mod - 2, mod) % mod;
    }
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", (ll)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }
    return 0;
}