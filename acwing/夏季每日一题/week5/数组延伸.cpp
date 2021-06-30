#include <iostream>
#include <algorithm>
#include <cstring>
#include<vector>
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
int a[N];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll ans = 0, psum = 0;
        int n, x;
        cin >> n >> x;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int cnt = N;
        for (int i = 0; i < n; i++)
        {
            ans += a[i];
            int c = 0;
            for (int j = a[i]; j % x == 0;j/=x)//延伸c次的最小值
                c++;
            if(c<cnt)
            {
                cnt = c;
                psum = ans - a[i];
            }
        }
        printf("%lld\n", ans*(cnt+1)+psum);
    }
    return 0;
}
