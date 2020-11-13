#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll n,ll k)
{
    if(n<k) return 0;
    ll a=n/k+n%k;
    return n/k+f(a,k);
}
int main()
{
    ll n,k;
    while(cin>>n>>k)
    {
        ll ans=f(n,k)+n;
        cout<<ans<<endl;
    }
    return 0;
}