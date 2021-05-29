#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int quick_sort(int q[], int l, int r,int k)
{
    if (l >= r)
        return q[l];
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        while(q[++i]<x)
            ;
        while(q[--j]>x)
            ;
        if(i<j)
            swap(q[i], q[j]);
    }
    int  sl=j - l + 1;
    if(k<=sl)
        return quick_sort(q, l, j, k);
    else
        return quick_sort(q, j + 1, r, k - sl);

}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cout<<quick_sort(a, 0, n - 1,k);
    return 0;
}