#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
long long dp[N];
int vis[N];
int prime[N];
int p(int x)
{
    memset(vis,1,sizeof(vis));
    for(int i=2;i<=x;i++){
        if(vis[i]){
            for(int j=2*i;j<=x;j+=i){
                vis[j]=0;
            }
        }
    }
    int cnt=0;
    for(int i=2;i<=x;i++){
        if(vis[i]){
            prime[++cnt]=i;
        }
    }
    return cnt;
}
int main()
{
    int i,j,n;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    cin>>n;
    int num=p(n);
    //cout<<num<<endl;
    for(i=1;i<=num;i++){
        for(j=prime[i];j<=n;j++){
            dp[j]+=dp[j-prime[i]];
        }
    }
    cout<<dp[n]<<endl;
    //cout<<p(100)<<endl;
    //for(int i=1;i<=25;i++){
    //    cout<<prime[i]<<" ";
    //}
    return 0;
}