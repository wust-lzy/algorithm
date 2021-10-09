#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], f1[N], f2[N];
int n;
int main()
{
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) //最长上升
    {
        cin >> a[i];
        f1[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && f1[i] < f1[j] + 1)
                f1[i] = f1[j] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) //倒序最长上升
    {
        f2[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j] && f2[i] < f2[j] + 1)
                f2[i] = f2[j] + 1;
        }
        ans = max(ans, f1[i] + f2[i] - 1);
    }
    cout << n - ans << endl;
    return 0;
}