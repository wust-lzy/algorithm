#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1010;
int f[N][N];//表示在第一个序列前i个字母，且在第二个序列前j个字母中出现的子序列
char a[N], b[N];
int main()
{
    int n, m;
    cin >> n >> m;
    scanf("%s", a+1);
    scanf("%s", b + 1);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            if(a[i]==b[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else    //继承i-1 ~j 和 i~j-1的最大值
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    cout << f[n][m];
    return 0;
}