#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi = acos(-1);
const int N = 1010;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    bool flag = true;
    double ans = 0;
    for (int i = n - 1; i >= 0;i--){
        if(flag)
            ans += pi * a[i] * a[i];
        else
            ans-= pi * a[i] * a[i];
        flag = !flag;
    }
    printf("%.6lf\n", ans);
    return 0;
}