#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        scanf("%lld %lld", &n, &k);
        string ans(n, 'a');
        for (int i = n-1; i ; i--)
        {
            if (k > n-i)
                k -= n - i;
            else
            {
                ans[i - 1] = ans[n - k] = 'b';
                cout << ans << endl;
                break;
            }
        }
    }
    return 0;
}