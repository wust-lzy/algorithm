#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 2 * (n - i); j++)
            printf(" ");
        for (int j = 0; j <= i; j++)
        {
            printf("%d", j);
            if (j != i)
                printf(" ");
        }
        for (int j = i - 1; j >= 0; j--)
            printf(" %d", j);
        printf("\n");
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2 * (n-i); j++)
            printf(" ");
        for (int j = 0; j <= i; j++)
        {
            printf("%d", j);
            if (j != i)
                printf(" ");
        }
        for (int j = i - 1; j >= 0; j--)
            printf(" %d", j);
        printf("\n");
    }
    return 0;
}
/*
    0
  0 1 0
  0 1 2 1 0
  0 1 0
  0

    0
  0 1 0
0 1 2 1 0
  0 1 0
    0
*/
