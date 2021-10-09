#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int a[N][N], f[N][N];
int n;
int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            f[i][j] = a[i][j];
            if (i > 1 && j > 1)
                f[i][j] += min(f[i - 1][j], f[i][j - 1]);
            else if (i > 1)
                f[i][j] += f[i - 1][j];
            else
                f[i][j] += f[i][j - 1];
        }
    }
    cout << f[n][n] << endl;
    return 0;
}