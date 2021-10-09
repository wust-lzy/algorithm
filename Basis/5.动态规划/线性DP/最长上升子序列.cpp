#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e3+10;
int a[N];
int dp[N];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
        }
    cout << ans;
    return 0;
}