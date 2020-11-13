#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    long long a[100005],b[100005];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(a[0]==a[n-1])
    {
        cout<<n;
        return 0;
    }
    for(i=0;i<n-1;i++)
        b[i]=a[i+1]-a[i];
    long long g=__gcd(b[0],b[1]);
    for(i=1;i<n-1;i++)
        g=__gcd(g,b[i]);
        cout<<(a[n-1]-a[0])/g+1;
    return 0;
}
