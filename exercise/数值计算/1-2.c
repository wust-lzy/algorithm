#include <stdio.h>
#include <math.h>
const int MAX = 20;
const int n = 4;
double a[4][4] = {
    {2, 10, 0, -3},
    {-3, -4, -12, 13},
    {1, 2, 3, -4},
    {4, 14, 9, -13}};
double l[20][20],u[20][20];
void work(double a[][n]){  //传入矩阵
    int i, j, k;
    double b[MAX], x[MAX], y[MAX];
    for (i = 0; i < n; i++) l[i][i] = 1;//初始化L矩阵的对角线的值
    for (k = 0; k < n; k++){
        for (j = k; j < n; j++){//计算ｕ的第一行到第K行元素
            u[k][j] = a[k][j];
            for (i = 0; i <= k - 1; i++)
                u[k][j] -= (l[k][i] * u[i][j]);}
        for (i = k + 1; i < n; i++){//计算L的第一列到第K列元素
            l[i][k] = a[i][k];
            for (j = 0; j <= k - 1; j++)
                l[i][k] -= (l[i][j] * u[j][k]);
            l[i][k] /= u[k][k];}
    }
    for (i = 0; i < n; i++){    y[i] = b[i];    //解方程组Ly=b
        for (j = 0; j <= i - 1; j++)
            y[i] -= (l[i][j] * y[j]);
    }
    for (i = n - 1; i >= 0; i--){ //解方程组Ux=y
        x[i] = y[i];
        for (j = i + 1; j < n; j++)
            x[i] -= (u[i][j] * x[j]);
        x[i] /= u[i][i];
    }
}
void show()
{
    int i, j;
    printf("矩阵L的值如下:\n");
    for (i = 0; i < n; i++)
    {
        printf("[");
        for (j = 0; j < n; j++)
        {
            printf("%lf ", l[i][j]);
        }
        printf("]\n");
    }
    printf("矩阵u的值如下:\n");
    for (i = 0; i < n; i++)
    {
        printf("[");
        for (j = 0; j < n; j++)
        {
            printf("%lf ", u[i][j]);
        }
        printf("]\n");
    }
}
int main()
{
    work(a);
    show();
    return 0;
}
/*
2 10 0 -3
-3 -4 -12 13
1 2 3 -4
4 14 9 -13
*/
