#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 15, M = 1010;
char str[M][N];
int f[N][N];

int check(char a[], char b[])//dp算法 同最短编辑距离
{
    int la = strlen(a+1), lb = strlen(b+1);
    memset(f, 0, sizeof f);
    for (int i = 0; i <= lb; i++)
        f[0][i] = i;
    for (int i = 0; i <= la; i++)
        f[i][0] = i;
    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    return f[la][lb];
}
int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++)
        scanf("%s", str[i] + 1);
    while (t--)
    {
        char target[N];
        int x;
        scanf("%s %d", target + 1, &x);
        int cnt = 0;
        for (int i = 0; i < n; i++)//遍历一遍所有的字符串 是否符合
        {
            if(check(str[i],target)<=x)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}