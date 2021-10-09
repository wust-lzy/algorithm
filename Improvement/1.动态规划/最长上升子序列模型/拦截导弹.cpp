#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N], dp[N], f[N];//有多少个导弹系统等同于最长上升子序列的长度
int n; //假设有k个系统 每个系统都是不递增的 那么第二组一定有一个比第一组的大，第三组有比第二组的大
int main()
{
    string line;
    getline(cin, line);
    stringstream ssin(line);
    while (ssin >> a[n])
        n++;
    int ans = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] <= a[j])
                f[i] = max(f[i], f[j] + 1);
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, f[i]);
        ans2 = max(ans2, dp[i]);
    }
    cout << ans << endl;
    cout << ans2 << endl;
    return 0;
}