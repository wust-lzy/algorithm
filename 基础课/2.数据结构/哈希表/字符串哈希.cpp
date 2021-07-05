#include <iostream>
#include<algorithm>
#include<cstring>
typedef unsigned long long ull;
using namespace std;

const int N = 1e5 + 10, P = 131;
char str[N];
ull h[N], p[N];

ull get(int l,int r)//核心函数，获取一段字符的哈希值
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    int n, m;
    scanf("%d %d %s", &n, &m, str + 1);
    p[0] = 1;
    for (int i = 1; i <= n;i++)
    {
        p[i] = p[i - 1] * P;//存取p的i次方
        h[i] = h[i - 1] * P + str[i];
    }
    while(m--)
    {
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if(get(l1,r1)==get(l2,r2))
            puts("Yes");
        else
            puts("No");
    }
        return 0;
}