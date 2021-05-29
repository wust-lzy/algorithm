#include<bits/stdc++.h>
using namespace std;
int dp[1100],w[110],val[110];
int main()
{
    //cout<<123;
    int t,m,i,j;
    cin>>t>>m;
    for(i=1;i<=m;i++){
        cin>>w[i]>>val[i];
    }
    for(i=1;i<=m;i++){
        for(j=t;j>=w[i];j--){
            dp[j]=max(dp[j-w[i]]+val[i],dp[j]);
        }
    }
    cout<<dp[t];
    return 0;
}
