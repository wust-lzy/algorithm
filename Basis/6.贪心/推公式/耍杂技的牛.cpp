#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 5e4+5;
struct cow
{
    int w;
    long long s;
}cows[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d %d", &cows[i].w, &cows[i].s);
    sort(cows + 1, cows + n + 1, [](cow &a, cow &b)
         { return a.s + a.w < b.w + b.s; });
    int ans = -1e9;
    for (int i = 1; i <=n ;i++)//按照w[i]+s[i]从小到大排的顺序最优
    {
        int t = cows[i].w;//自己的重量不算
        cows[i].w += cows[i -1].w;
        ans = max(ans,(int)(cows[i].w-t-cows[i].s));
    }
    cout << ans;
    return 0;
}