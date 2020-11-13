#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,m,t,i;
    ll sum=0;
    cin>>n>>m;
    if(!m)
    {
       for(i=0;i<n+m+1;i++)
    {
        cin>>t;
        sum+=t;
    }
    cout<<sum;
    return 0;
    }
    else
    {
        ll Max=-1e18,Min=1e18;
        for(i=0;i<n+m+1;++i)
        {
            cin>>t;
            sum+=abs(t);
            if(t>Max)
                Max=t;
            if(t<Min)
                Min=t;
        }
        if(Min>0)
            sum-=2*Min;
        if(Max<0)
            sum+=2*Max;
        cout<<sum;
    }
    return 0;
}

