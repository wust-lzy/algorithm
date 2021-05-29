#include<iostream>
using namespace std;
int f[1005][1005];
int main()
{
    int n,v,w[105], val[105], i, j;
    cin >> v >> n;
    for (i = 1; i <= n;i++)
        cin >> w[i] >> val[i];
    for (i = 1; i <= n;i++)
        for (j = 0; j <= v;j++)
        {
            f[i][j] = f[i - 1][j];
            if(j>=w[i])
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + val[i]);
        }
    cout << f[n][v];
    return 0;
}
