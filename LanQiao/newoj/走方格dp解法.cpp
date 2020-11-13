#include<bits/stdc++.h>
using namespace std;
//dp[i][j]表示点(i,j)有多少种走法
int n,m,dp[35][35];
int main()
{
    cin>>n>>m;
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)  continue;
            if((i&1) || (j&1))
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}