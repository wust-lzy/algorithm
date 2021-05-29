#include<iostream>
using namespace std;
typedef long long ll;
ll  n, v, w[10005], val[10005], i, j;
ll f[10000005];
int main()
{
    cin >> v >> n;
    for (i = 1; i <= n;i++)
        cin >> w[i] >> val[i];
    for (i = 1; i <= n;i++)
    {
        for (j = w[i]; j <= v;j++)
        {
            f[j] = max(f[j], f[j - w[i]] + val[i]);
        }
    }
    cout << f[v];
    return 0;
}
