#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    return a%b==0?b:gcd(b,a%b);
}
int main()
{
    int ans=0;
    for(ll i=1;i<=2020;i++)
    for(ll j=1;j<=2020;j++)
    {
        if(gcd(i,j)==1)
        ans++;
    }
    cout<<ans;
    return 0;
}