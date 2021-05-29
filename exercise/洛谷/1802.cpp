#include<bits/stdc++.h>
using namespace std;
int main()
{
    //dp[i]表示用i瓶药获得最大的经验值
    long long n,x,i,j,dp[10050],lose[10050],win[10050],use[10050];
    cin>>n>>x;
    for(i=1;i<=n;i++){
        cin>>lose[i]>>win[i]>>use[i];
    }
    for(i=1;i<=n;i++){
        //如果可以赢
        for(j=x;j>=use[i];j--){
            dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
        }
        //打不过也可以得经验
        for(j=use[i]-1;j>=0;j--){
            dp[j]+=lose[i];
        }
    }
    dp[x]*=5;
    cout<<dp[x]<<endl;
    return 0;
}