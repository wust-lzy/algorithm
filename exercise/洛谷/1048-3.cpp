#include<iostream>
using namespace std;
int f[1005];
int main()
{
    int n,v,w[105], val[105], i, j;
    cin >> v >> n;
    for (i = 1; i <= n;i++)
        cin >> w[i] >> val[i];
    for (i = 1; i <= n;i++)
    {
        for (j = v; j >= 0;j--)
        {
            if(j>=w[i])
            {
                f[j] = max(f[j], f[j - w[i]] + val[i]);
            }
        }
    }
    cout << f[v];
    return 0;
}
