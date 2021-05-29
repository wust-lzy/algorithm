#include <stdio.h>
#include <math.h>
const double eps = 1e-5;                                     //定义精度
const double a = 0, b = 1;                                   //积分上限和下限
double ans[15][15];                                          //答案数组
double Tn(double (*f)(double x), double a, double b, int n); //计算Tn
double Rom(double T0, double T1, int m);                     //递推公式
double fx(double x);                                         //积分函数

double fx(double x) //积分函数
{
    if (!x)
        return 1;
    return sin(x) / x;
}
double Tn(double (*f)(double x),double a,double b,int n) //计算Tn  f为积分函数 a，b为积分上下线 n为阶数
{
    int i;
    double h = (b - a) / n; //步长
    double ans = f(a) + f(b); //加上f(a)和f(b)
    double Xi = a;
    for (i = 1; i <= n - 1;i++)//加上f(Xi)*h/2
    {
        Xi += h;
        ans += 2 * f(Xi);
    }
    return ans * h / 2;
}
double Rom(double T0, double T1, int m) //龙贝格法递推公式
{
    return (pow(4, m) * T1 - T0) / (pow(4, m) - 1); //通过线性组合外推
}
int work()  //返回达到精度时候的层数
{
    int flag = 1;   //循环标记，若精度达到要求，则结束循环
    int cnt = 0, i, j;
    for (i = 0; i <= 10; i++) //用Tn公式初始化第一列
    {
        int t = pow(2, i);
        ans[i][0] = Tn(fx, a, b, t);
    }
    while (flag && cnt < 10)  //层数小于10，或者未达到精度
    {
        cnt++;
        for (i = 1; i <= cnt; i++) //横向外推
        {
            ans[cnt][i] = Rom(ans[cnt - 1][i - 1], ans[cnt][i - 1], cnt);
        }
        if (fabs(ans[cnt][cnt] - ans[cnt][cnt - 1]) <= eps) //判断每一行是否达到要求
        {
            flag = 0;
        }
    }
    return cnt; //返回精度达到要求时的层数
}
void show(int cnt)
{
    int i,j;
    for (i = 0; i <= cnt; i++)
    {
        printf("第%d层：", i);
        for (j = 0; j <= i;j++)
            printf("T%d(%d):%lf ", j, i - j, ans[i][j]);
        printf("\n");
    }
    printf("----------------------------------\n");
    printf("此时第%d层达到精度要求\n", cnt);
    printf("此时T%d(0)为：%lf\n",cnt, ans[cnt][cnt]);
    printf("此时T%d(1)为：%lf\n",cnt-1, ans[cnt][cnt - 1]);
    printf("精度为：%lf\n", fabs(ans[cnt][cnt] - ans[cnt][cnt - 1]));
}
int main()
{
    int cnt=work(); //n从1开始
    show(cnt);
    return 0;
}
