#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long LL;
const int maxn = 110;
LL dp[maxn][maxn]; 
///dp[l][r]=v记录的是当前层中的[l,r]的方法数为v（初始dp是dp[n][l][r]）
///转移为dp[l][r]+=dp[l-1][r]+dp[l][r+1]-dp[l-1][r+1](因为dp[l-1][r]和dp[l][r+1]中包括的是[l-1,r+1]+[l,r]所以要减去)
///由题意可知初始化为第n层的方法数，即从大区间枚举到小区间后得出的方法数
///转移时若[l，r]中没有X，则方法数为dp[l][r]+=dp[l-1][r]+dp[l][r+1]-dp[l-1][r+1]，相当于向上传递，反之从这一层开始[l,r]区间的方法数就为0
int check[maxn][maxn];
int main()
{
    int n, m;
    char str[maxn];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++)
        {
            check[i][j] = check[i][j - 1]; ///一个比较巧妙的方法
            if (str[j] == 'X')
            {
                check[i][j]++;
            }
        }
    }
    LL ans = 1; ///没有放也是一种
    for (int i = 1; i <= m; i++)
    { ///初始化
        for (int j = m; j >= i; j--)
        {
            if (check[n][j] - check[n][i - 1] == 0)
            {
                ans++;
                dp[i][j] = dp[i][j + 1] + dp[i - 1][j] - dp[i - 1][j + 1] + 1;
            }
        }
    }
    for (int t = n - 1; t > 0; t--)
    { ///状态
        for (int i = 1; i <= m; i++)
        {
            for (int j = m; j >= i; j--)
            {
                if (check[t][j] - check[t][i - 1] == 0)
                {
                    ans = (ans + dp[i][j]) % MOD;
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j + 1] - dp[i - 1][j + 1]) % MOD;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}