#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e6+5;
int a[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n;i++)  //中位数是最小的
        ans+= abs(a[i] - a[n / 2]);
    cout << ans;
    return 0;
}