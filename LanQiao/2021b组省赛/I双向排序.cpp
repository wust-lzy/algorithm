#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n;i++)
        a[i] = i + 1;
    for (int i = 0; i < m;i++)
    {
        int p, q;
        scanf("%d %d", &p, &q);
        if(p==0)
            sort(a, a + q,cmp);
        else
            sort(a + q - 1, a + n);
    }
    for (int i = 0; i < n;i++)
    {
        printf("%d", a[i]);
        if(i!=n-1)
            printf(" ");
    }
    return 0;
}