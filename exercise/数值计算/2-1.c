#include <stdio.h>
#define MAX 20
const int n = 3;
const double x = 0.5635; //要计算的函数值
typedef struct stnode   //点的结构
{
    double x;
    double y;
} Point;
Point points[4] = {{0.56160, 0.82741}, {0.56280, 0.82659}, {0.56401, 0.82577}, {0.56521, 0.82495}};
void work(Point points[]) //传入数值
{
    int i, j;
    double tmp, lagrange = 0;
    for (i = 0; i <= n; i++)//计算f(x)
    {
        for (j = 0, tmp = 1; j <= n; j++)
        {
            if (i == j) //xi!=xj
                continue; //j!=k
            tmp = tmp * (x - points[j].x) / (points[i].x - points[j].x);
        }
        lagrange = lagrange + tmp * points[i].y; //计算基函数*y,全部加起来，就是该x项的拉格朗日函数了
    }
    printf("\n拉格朗日函数f(%lf)=%lf\n", x, lagrange);
}
int main()
{
    work(points);
    return 0;
}
/*
0.56160 0.82741 0.56280 0.82659 0.56401 0.82577 0.56521 0.82495
*/
