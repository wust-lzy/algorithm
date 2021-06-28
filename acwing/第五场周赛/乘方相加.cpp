#include <iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int N = 100;
int s[N];
int main()
{
    int T;
    cin >> T;
    while(T--)//一个数用k进制数表示
    {
        int n, k;
        cin >> n >> k;
        ll maxn = -1;
        bool flag = true;
        memset(s, 0, sizeof s);
        while(n--)
        {
            ll x;
            cin >> x;
            for (int j = 0; x;j++,x/=k)
                s[j] += x % k;
        }
        for (int i = 0; i < N;i++)
            if(s[i]>1)//每个k进制数只能用一次 超过一次就gg
                flag = false;
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}