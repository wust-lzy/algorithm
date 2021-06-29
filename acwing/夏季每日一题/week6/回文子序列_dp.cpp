#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

const int N = 5005;
int a[N];
int dp[N][N];
int main()
{
    int t, n, x;
    cin >> t;
    while(t--){
        bool flag = false;
        int ans = 0;
        cin >> n;
        for (int i = 0; i < n;i++)
            scanf("%d", &a[i]);
        for (int i = n-1; i < n;i++)//dp[i][j]表示第i个字符到第j个字符的最长回文子序列
        {
            for (int j = i + 1; j < n;j++){
                dp[i][i] = 1;
                if(a[i]==a[j])//a[i]=a[j] dp[i,j]=dp[i+1,j-1]+2
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else    //max(dp[i+1,j] ,dp [i,j-1] )
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                ans = max(ans, dp[i][j]);
            }
        }
        printf("%s\n", ans>=3 ? "YES" : "NO");
    }
    return 0;
}