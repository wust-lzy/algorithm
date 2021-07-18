#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    unordered_map<int,ll>m;//i+a[j]=j+a[i]
    int n,x;    //等价于 i-a[i]=j-a[j]
    cin>>n;
    for(int i=0;i<n;i++)//
    {
        scanf("%d",&x);
        m[i-x]+=x;    //每个属性求和
    }
    ll ans=0;
    for(pair<const int,ll> &e:m){
        ans = max(ans, e.second);
    }
    cout << ans;
    return 0;
}