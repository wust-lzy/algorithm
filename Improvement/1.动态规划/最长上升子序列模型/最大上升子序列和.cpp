#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int a[N];
int f[N];//记录最大递增序列和
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[i] = a[i];
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && f[i]<f[j]+a[i])
                f[i] = f[j] + a[i];
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}