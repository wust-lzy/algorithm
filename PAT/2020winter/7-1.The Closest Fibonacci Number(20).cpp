#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll f[105];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 50;i++)
        f[i] = f[i - 1] + f[i - 2];
    ll dir = 1e10;
    int index = -1;
    int n;
    cin >> n;
    for (int i = 1; i <= 50;i++)
    {
        if(abs(f[i]-n)<dir)
        {
            dir = abs(f[i] - n);
            index = i;
        }
    }
    cout << f[index];
    return 0;
}