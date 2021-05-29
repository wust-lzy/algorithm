#include <stdio.h>
#define MAX 20
const int n = 3;
const double x = 0.5635; //要计算的函数值
typedef struct stnode//点的结构
{
    double x;
    double y;
} Point;
Point points[4] = {{0.56160, 0.82741}, {0.56280, 0.82659}, {0.56401, 0.82577}, {0.56521, 0.82495}};
void work(Point points[]) //传入数值
{
    int i, j;
    double form[MAX + 1];   //保存差商表
    double tmp, newton = 0; //x是计算的f(x)插值点
    for (i = 0; i <= n; i++)//初始化
        form[i] = points[i].y;
    for (i = 0; i < n; i++)
    {
        for (j = n; j > i; j--)//差商的计算
        {
            form[j] = (form[j] - form[j - 1]) / (points[j].x - points[j - 1 - i].x);
        }
    }
    tmp = 1;
    newton = form[0];
    for (i = 0; i < n; i++)
    {
        tmp = tmp * (x - points[i].x);       //差商乘以牛顿插值函数
        newton = newton + tmp * form[i + 1]; //
    }
    printf("\n牛顿插值函数N(%lf) = %lf \n", x, newton);
}
void show()
{
    int i;
    printf("插值点的x值和y值为：\n");
    for (i = 0; i <= n; i++)
        printf("%lf %lf\n", points[i].x, points[i].y);
    //牛顿插值多项式的x值
    printf("\n计算牛顿插值多项式的x值:%llf", x);
}
int main()
{
    show();
    work(points);
    return 0;
}
/*
0.56160 0.82741 0.56280 0.82659 0.56401 0.82577 0.56521 0.82495
*/
