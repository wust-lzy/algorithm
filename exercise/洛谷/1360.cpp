#include<bits/stdc++.h>
using namespace std;
int main()
{
    //v[i]是i物品的价格，w[i]是重要程度,dp[j]表示j重量最大的价值
    long long n,m,i,j,v[30],w[30],dp[30005];//m为总重量,n为容量
    cin>>m>>n;
    for(i=1;i<=n;i++){
        cin>>v[i]>>w[i];
        w[i]*=v[i];
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=v[i];j--){
            //选第i件物品和不选 求最大值
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}