#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        scanf("%d", &n);
        fill(a, a + n+2, 0);//差分数组
        for (int i = 1; i <= n;i++)
        {
            int x;
            scanf("%d", &x);
            int l = max(1, i - x + 1), r = i;
            a[l]++, a[r + 1]--;
        }
        for (int i = 1; i <= n;i++)
        {
            a[i] += a[i - 1];//差分数组变为原数组
            printf("%d ", !!a[i]);
        }
        puts("");
    }
    return 0;
}