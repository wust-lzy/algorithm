#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int a[N];
ll s[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", s[y] - s[x - 1]);
    }
    return 0;
}