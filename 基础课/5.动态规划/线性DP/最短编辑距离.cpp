#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1010;
int f[N][N];//从a[1~i]变成b[1~j]的操作方式
char a[N], b[N];

int main()
{
    int n, m;
    cin >> n;
    scanf("%s", a + 1);
    cin >> m;
    scanf("%s", b + 1);
    for (int i = 0; i <= m;i++)//初始化 a的长度为0，插入i个字符为b
        f[0][i] = i;
    for (int i = 0; i <= n;i++)//同理
        f[i][0] = i;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            if(a[i]==b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    cout << f[n][m];
    return 0;
}