#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        ll x=0,y=0;
        x=(1+m)*m/2*(1+n)*n/2;//总的
        for(int i=1;i<=min(m,n);i++)
        {
            y+=(m-i+1)*(n-i+1); //正方形
        }
        x-=y;
        cout<<y<<" "<<x<<endl;
    }
    return 0;
}