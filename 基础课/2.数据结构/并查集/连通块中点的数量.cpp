#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int father[N], se[N];
//路径压缩
int findfather(int x)
{
    if(father[x]!=x)
        father[x] = findfather(father[x]);
    return father[x];
}
//维护集合中元素的个数
void Union(int a,int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb)//已经在一个集合里面就不需要维护了
    {
        se[fb] += se[fa];
        father[fa] = fb;
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n;i++)
    {
        father[i] = i;
        se[i] = 1;
    }
    while(m--)
    {
        char c[2];
        int a, b;
        scanf("%s %d", c, &a);
        if(c[0]=='C')
        {
            scanf("%d", &b);
            Union(a, b);
        }
        else if(c[1]=='1')
        {
            scanf("%d", &b);
            printf("%s\n", findfather(a) == findfather(b) ? "Yes" : "No");
        }
        else{
            printf("%d\n", se[findfather(a)]);
        }
    }
    return 0;
}