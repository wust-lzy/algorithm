#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N], tmp[N];
void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while (i <= mid) //两边没归并完 接到后面去
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
    return 0;
}
