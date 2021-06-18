#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int a[N], q[N];
int hh = 0, tt = -1;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
        //判断队头是否出队 i-k+1代表起点
        while(hh<=tt&&i-k+1>q[hh])
            hh++;
        while(hh<=tt&&a[q[tt]]>=a[i])
            tt--;
        q[++tt] = i;
        if(i>=k-1)
            printf("%d ", a[q[hh]]);
    }
    puts("");
    hh = 0, tt = -1;
    for (int i = 0; i < n;i++)
    {
        //判断队头是否出队 i-k+1代表起点
        while(hh<=tt&&i-k+1>q[hh])
            hh++;
        while(hh<=tt&&a[q[tt]]<=a[i])
            tt--;
        q[++tt] = i;
        if(i>=k-1)
            printf("%d ", a[q[hh]]);
    }
        return 0;
}