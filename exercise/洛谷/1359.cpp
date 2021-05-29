#include<bits/stdc++.h>
using namespace std;
int main()
{
    //r[i][j]表示i站到j站的价格,dp[i]表示从i到n的最小价格
    int i,j,r[205][205],dp[205],n;
    cin>>n;
    for(i=1;i<n;i++)//初始化dp[i]   i属于[1,n-1]
    {
        for(j=i+1;j<=n;j++)
        cin>>r[i][j];
        dp[i]=1e9;
    }
    for(i=n-1;i>0;i--){
        for(j=i+1;j<=n;j++){
            dp[i]=min(dp[i],dp[j]+r[i][j]);
        }
    }
    cout<<dp[1];
    return 0;
}