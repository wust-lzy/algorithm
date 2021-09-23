#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int a[N], b[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i] - a[i - 1];//构造差分数组
    }
    while(m--){
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        b[l] += c;//前面一段加上c
        b[r + 1] -= c;//后面一段减去c
    }
    for (int i = 1; i <= n;i++)//对b求前缀和 得到a数组
    {
        b[i] += b[i - 1];
        printf("%d", b[i]);
        if(i!=n)
            printf(" ");
    }
        return 0;
}