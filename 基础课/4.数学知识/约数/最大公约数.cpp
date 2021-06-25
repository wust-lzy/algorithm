#include <iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;

ll gcd(ll a,ll b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}