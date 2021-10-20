#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N = 25010;
int a[N];
bool f[N];
int t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof f);
        f[0] = true;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int cnt = 0, m = a[n - 1];
        for (int i = 0; i < n; i++) //判断a[i]能不能被a[0]~a[i-1]凑出来
        {
            int v = a[i];
            if (!f[v]) //不能凑出来 必选
                cnt++;
            for (int j = v; j <= m; j++)
                f[j] |= f[j - v];
        }
        cout << cnt << endl;
    }
    return 0;
}