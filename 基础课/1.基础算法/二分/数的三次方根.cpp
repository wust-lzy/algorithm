#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double n;
    cin >> n;
    double l = -10000, r = 10000;
    const double eps = 1e-8;
    while(r-l>eps){
        double mid = (l + r) / 2;
        if(mid*mid*mid>=n)
            r = mid;
        else
            l = mid;
    }
    printf("%06lf\n", l);
    return 0;
}