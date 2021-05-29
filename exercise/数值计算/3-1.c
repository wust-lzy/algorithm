#include <stdio.h>
#include<math.h>
const double eps = 1e-5; //定义精度
const double a = 0, b = 1;//积分上限和下限
double fx(double x) //积分函数
{
    if(!x)
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
    return ans * h / 2; //返回Tn
}
double T2n(double (*f)(double x),double a,double b,int n) //计算T2n f为积分函数 a，b为积分上下线 n为阶数
{
    int i;
    double h = (b - a) / n;//步长
    double ans = Tn(fx, a, b, n) / 2; //加上Tn/2
    double Xi = a + h / 2;  //Xi为a加上一半的步长
    for (i = 0; i <= n - 1;i++) //加上f(Xi+1/2)*h/2
    {
        ans += h * f(Xi) / 2;
        Xi += h;
    }
    return ans;//返回T2n
}
void work(int n)
{
    int flag = 1;
    while(flag)
    {
        double T1 = Tn(fx, a, b, n);  //Tn
        double T2 = T2n(fx, a, b, n); //T2n
        if(fabs(T2-T1)<=eps)//满足要求时
        {
            flag = 0;
            printf("此时的n为：%d\n", n);
            printf("此时Tn为：%lf\n",T1);
            printf("此时T2n为：%lf\n", T2);
            printf("T2n-Tn的精度为：%lf\n", fabs(T2-T1));
        }
        else
            n *= 2;
    }
}
int main()
{
    work(1); //n从1开始
    return 0;
}
