#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll x, y;
    for (x = 2020;;x++)
    {
        ll t = 2 * x * x - 2019 * 2019;
        if((ll)sqrt(t)*(ll)sqrt(t)==t)
        {
            ll sum = x + sqrt(t);
            cout << sum;
            break;
        }
    }
        return 0;
}