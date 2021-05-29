#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int dp[N];
int a[N];
int b[N];
int c[205][205];
int num[N];
int main()
{
    int n,m,i,j,cnt=0;
    cin>>m>>n;
    for(i=1;i<=n;i++){
        int C;
        cin>>a[i]>>b[i]>>C;
        //求一共有多少组
        cnt=max(cnt,C);
        num[C]++;//求序号为C的组物品的件数
        c[C][num[C]]=i;//记录序号为C组物品的序号
    }
    //1~k组
    for(int k=1;k<=cnt;k++){
        for(j=m;j>=0;j--){
            for(i=1;i<=num[k];i++){
                if(j>=a[c[k][i]]){
                    dp[j]=max(dp[j],dp[j-a[c[k][i]]]+b[c[k][i]]);
                }
            }
        }
    }
    cout<<dp[m];
    return 0;
}