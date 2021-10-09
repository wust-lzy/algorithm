#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 510;
int n, V1, V2;
int f[N][M]; //花费1为N，花费2为M的最大价值

int main()
{
    cin >> V1 >> V2 >> n;
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        for (int j = V1; j >= v1; j--)
            for (int k = V2 - 1; k >= v2; k--) //皮卡丘的体力大于0 最多只能花费V2-1体力
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
    }
    cout << f[V1][V2 - 1] << " ";
    int k = V2 - 1;
    while (k > 0 && f[V1][k - 1] == f[V1][V2 - 1])
        k--;
    cout << V2 - k;
    return 0;
}