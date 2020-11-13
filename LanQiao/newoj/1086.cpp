#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5005];
const ll mod=1e9+7;
long long C(ll n)
{
	return n*(n-1)/2;
}

int main()
{
    ll i,j,n,t,cnt=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t; 
        a[t]++;
    }
    for(i=1;i<=5000;i++)
    for(j=i;j<=5000&&i+j<=5000;j++)
    {
        if(i==j)
        {
            if(a[i]>=2&&a[i*2]>=2)
            cnt+=C(a[i])*C(a[i*2])%mod;
        }
        else
        {
            if(a[i]&&a[j]&&a[i+j]>=2)
            {
                cnt+=a[i]*a[j]*C(a[i+j])%mod;
            }
        }
        cnt%=mod;   
    }
    cout<<cnt;
    return 0;
}