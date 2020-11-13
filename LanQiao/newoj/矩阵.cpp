#include<bits/stdc++.h>
using namespace std;
//dp[i][j]表示枚举i个数，j个数放在第一行
int n=2020,dp[2030][2030];
int main()
{
    dp[1][1]=1;
    for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
    {
        dp[i][j]+=dp[i-1][j-1];//将第i个数放在第一行
        //保证第二行的数比第一行的大 所以第一行的数不能比第二行少
        if(i-j<=j)
        {
            dp[i][j]+=dp[i-1][j];//拿一个数放在第二行
        }
        dp[i][j]%=n;
    }
    cout<<dp[2020][1010]<<'\n';
    cout<<dp[2020][2020]<<'\n';
    return 0;
}