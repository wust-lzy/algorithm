#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e4 + 10;
int v[N], w[N];
int f[N];
int n, m;
int main()
{
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n;i++)//将n件物品 每件可以选s[i]次 拆分成n*s[i]件物品
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while(k<=s)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s>0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    n = cnt;
    for (int i = 1; i <= n;i++)//最后用01背包问题解决
        for (int j = m; j >= v[i];j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m];
    return 0;
}