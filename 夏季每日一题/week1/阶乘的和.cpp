#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10];
int f(int x)
{
    if (x == 1)
        return 1;
    return x * f(x - 1);
}
bool dfs(int n, int i, int sum)
{
    if (sum == n)
        return true;
    if (sum > n || a[i] > n||i>9)
        return false;
    return dfs(n, i + 1, sum + a[i]) || dfs(n, i + 1, sum);
}
int main()
{
    int n;
    a[0] = 1;
    for (int i = 1; i < 10; i++)
        a[i] = f(i);
    // for (int i = 0; i < 10;i++)
    //     cout << a[i] << endl;
    while (cin >> n)
    {
        if (n < 0)
            break;
        if (n < 1)
        {
            cout << "NO" << endl;
            continue;
        }

        if (dfs(n, 0, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}