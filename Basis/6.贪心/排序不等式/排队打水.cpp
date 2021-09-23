#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5;
int a[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);//从小到大排序
    long long ans = 0, sum = 0;
    for (int i = 1; i < n;i++)//t[0]等待n-1次,t[1]等待n-2次....t[k]等待n-k-1次
    {
        sum += a[i - 1];
        ans += sum;
    }
    cout << ans;
    return 0;
}