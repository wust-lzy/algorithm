#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[25], a[25], ans[25],q[25];
bool con[25][25];
int i, j, n;
int main()
{
    cin >> n;
    for (i = 1; i <= n;i++)
    {
        cin >> a[i];
        f[i] = a[i];
    }
    for (i = 1; i <= n - 1;i++)
    {
        for (j = i + 1; j <= n;j++)
            cin >> con[i][j];
    }
    for (i = 1; i <= n - 1;i++)
    {
        for (j = i + 1; j <= n;j++)
        if(con[i][j])
        {
            if(f[i]+a[j]>f[j])
            {
                f[j] = f[i] + a[j];
                q[j] = i;
            }
        }
    }
    int t = 1,tot=0;
    for (i = 1; i <= n;i++)
    {
        if(f[t]<f[i])
            t = i;
    }
    ans[0] = f[t];
    while(t)//记录路径,并查集？
    {
        ans[++tot] = t;
        t = q[t];
    }
    for (i = tot; i >= 1;i--)
    {
        cout <<ans[i];
        if(i!=1)
            cout << " ";
    }
    cout << endl<< ans[0];
    return 0;
}