#include <stdio.h>
#include <math.h>
const int n = 3; //初始化列数
//初始化矩阵
double A[3][3] =
    {{2.5, 2.3, -5.1},
     {5.3, 9.6, 1.5},
     {8.1, 1.7, -4.3}};
double B[3] = {3.7, 3.8, 5.5}; //解的值
void work(int n, double A[][n], double B[])
{                               //矩阵的列数，矩阵，解
    int i, j, k, i_index;       //列主元所在行的指标
    double m;                   //列主元的值
    for (k = 0; k < n - 1; k++) //k从1到~n-1
    {
        m = 0;
        i_index = k;
        for (i = k; i < n; i++)
        {
            if (fabs(A[i][k]) > m)
            {
                m = fabs(A[i][k]);
                i_index = i; //记录主元所在行的指标
            }
        }
        if (i_index != k)
        {
            for (j = k; j < n; j++) //换行
            {
                double a = A[i_index][j];
                A[i_index][j] = A[k][j];
                A[k][j] = a;
            }
            double b = B[i_index];
            B[i_index] = B[k];
            B[k] = b;
        }
        for (i = k + 1; i < n; i++) //归一化
        {
            A[i][k] = A[i][k] / A[k][k];
        }
        for (i = k + 1; i < n; i++) //消元
        {
            for (j = k + 1; j < n; j++)
            {
                A[i][j] = A[i][j] - A[i][k] * A[k][j];
            }
            B[i] = B[i] - A[i][k] * B[k];
        }
    }
    for (i = n - 1; i >= 0; i--) //回代过程
    {
        double b = 0;
        for (j = i + 1; j < n; j++)
        {
            b += A[i][j] * B[j];
        }
        B[i] = (B[i] - b) / A[i][i];
    }
}
void show()
{
    int i, j;
    printf("矩阵为:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n解xi=");
    for (i = 0; i < n; i++)
        printf("%lf ", B[i]);
}

int main()
{
    work(3, A, B);
    show();
    return 0;
}
