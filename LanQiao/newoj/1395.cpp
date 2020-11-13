#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 9;
typedef long long ll;
bool vis[maxn];
ll prime[maxn];
ll phi[maxn];
ll s[maxn];

const int mod = 1e9 + 7;
void Euler(int n)
{
    phi[1] = 1;
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * prime[j] <= n; j++)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j])
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
            else
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
    s[1] = phi[1];
    for (int i = 2; i < n; i++)
    {
        s[i] = s[i - 1] + 2 * phi[i];
    }
}
int main()
{
    int n;
    Euler(maxn);
    ll sum = 0;
    while (cin >> n)
    {
        sum = 0;
        for (ll i = 1; i <= n; i++)
            sum = (sum + s[n / i] % mod * i % mod * i % mod) % mod;
        cout << sum << endl;
    }
}