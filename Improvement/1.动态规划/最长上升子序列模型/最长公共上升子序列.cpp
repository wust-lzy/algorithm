#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
f[i][j]代表所有a[1 ~ i]和b[1 ~ j]中以b[j]结尾的公共上升子序列的集合
不包含a[i]的子集，最大值是f[i - 1][j]； (a[i]!=b[j])
包含a[i]的子集，(a[i]==b[j])    将这个子集继续划分，依据是子序列的倒数第二个元素在b[]中是哪个数：
子序列只包含b[j]一个数，长度是1；
子序列的倒数第二个数是b[1]的集合，最大长度是f[i - 1][1] + 1；
子序列的倒数第二个数是b[2]的集合，最大长度是f[i - 1][2] + 1；
…
子序列的倒数第二个数是b[j - 1]的集合，最大长度是f[i - 1][j - 1] + 1；
*/
const int N = 3010;
int a[N], b[N];
int f[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int maxn = 1;//优化一遍，求出a[j]>b[i]的情况下发f[i-1][j-1]+1 的最大值
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], maxn);
            if (a[i] > b[j])
                maxn = max(maxn, f[i - 1][j] + 1);
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}