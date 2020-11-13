// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const double eps = 1e-6;
// int n;
// double a, l, r, mid, h[1005];
// bool ok(double x)
// {
//     h[0] = a;
//     h[1] = x;
//     for (int i = 2; i < n;i++)
//     {
//         h[i] = 2 * h[i - 1] - h[i - 2] + 2;
//         if(h[i]<0)
//             return 0;
//     }
//     return 1;
// }
// int main()
// {
//     cin >> a >> n;
//     for (int i = 0; i < n;i++)
//         h[i] = 0.00;
//     l = a / 2 - 1;
//     r = a;
//     while (r-l>eps)
//     {
//         mid = (l + r)/2;
//         if(ok(mid))
//             r = mid;
//         else
//         {
//             l = mid;
//         }
//     }
//     printf("%0.2lf", h[n - 1]);
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// const double mina=1e-6;
// int n;
// double a,l,r,mid,lp[1010];
// bool judge(double x)//每次二分暴力的判断一下是否有点小于0
// {
//     lp[1]=a;
//     lp[2]=x;
//     for(int i=3;i<=n;i++)
//     {
//         lp[i]=2*lp[i-1]-lp[i-2]+2;
//         if(lp[i]<0)return false;
//     }
//     return true;
// }
// int main()
// {

//     while(scanf("%d%lf",&n,&a)!=EOF)//scanf是有返回值的，返回读入的个数，如果没有的话返回EOF
//     {
//         for(int i=0;i<=1009;i++)lp[i]=0.00;
//         l=a/2-1;//这里可以优化一下二分的范围，因为这个值刚好使第3个点为0
//         r=a;//随便设个高一点的值即可
//         while(r-l>mina)//保证精度
//         {
//             mid=(l+r)/2;
//             if(judge(mid)==true)r=mid;//满足的话就可以再小一点
//             else l=mid;//不满足的话就增大
//         }
//         printf("%0.2lf\n",fabs(lp[n]));
//         getchar();//读走回车
//     }
// return 0;
// }//看懂了记得点赞QWQ
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int N = 1005;
int n;
double a, k[N], b[N];

double solve()
{
    double ans = 0;
    k[1] = 0;
    b[1] = a;
    k[2] = 1;
    b[2] = 0;
    for (int i = 3; i <= n; i++)
    {
        k[i] = 2 * k[i - 1] - k[i - 2];
        b[i] = 2 * b[i - 1] - b[i - 2] + 2;
        if (ans * k[i] + b[i] < 0)
            ans = -b[i] / k[i];
    }
    return k[n] * ans + b[n];
}

int main()
{
    while (scanf("%d%lf", &n, &a) == 2)
    {
        printf("%.2lf\n", solve());
    }
    return 0;
}