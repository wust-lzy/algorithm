#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, m;
int a[205], w[205][205], dp[205][205];
//dp[i][j]表示前i个数中，去掉j个数的最大和 保留第i个数
int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= m;i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            scanf("%d", &w[i][j]);
        }
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[1][0] = 0; //第一个数  保留他自己
    for (int i = 2; i <= m;i++){
        for (int j = 0; j <= k;j++){ //枚举删除的个数
        //u表示中间的点  删除u~i中间所有的数  收益就为dp[u][剩余删除的数]+w[a[u]]w[a[i]]
            for (int u = 1; u < i;u++){   
                if(j>=(i-u-1))
                {
                    dp[i][j] = max(dp[i][j], dp[u][j - (i - u - 1)] + w[a[u]][a[i]]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k;i++){    //枚举删除数中最大的收益
        ans = max(ans, dp[m][i]);
    }
    cout << ans;
    return 0;
}