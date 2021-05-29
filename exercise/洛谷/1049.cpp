#include<bits/stdc++.h>
using namespace std;
int main()
{
    //dp[i]表示用i
    long long n,m,i,j,dp[21000],v[50];
    cin>>m>>n;
    for(i=1;i<=n;i++){
        cin>>v[i];
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
    }
    long long ans=m-dp[m];
    cout<<ans<<endl;
    return 0;
}