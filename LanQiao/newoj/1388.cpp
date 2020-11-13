#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,k,ans=0,i;
    cin>>n>>k;
    for(i=2;i<=n;i++)
    ans=(ans+k)%i;

    cout<<ans+1;
    return 0;
}