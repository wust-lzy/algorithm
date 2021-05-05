#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n;
    int mod = 3600 * 24;//一天的秒数
    cin >> n;
    n /= 1000;
    n %= mod;
    int h = (n / 3600) % 24;
    int m = ((n % 3600)/60)%60;
    int s = n % 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}