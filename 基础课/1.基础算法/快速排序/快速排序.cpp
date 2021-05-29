#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int q[N];
void q_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while (q[i] < x);
        do
        {
            j--;
        } while (q[j] > x);
        if(i<j)
            swap(q[i], q[j]);
    }
    q_sort(q, l, j);
    q_sort(q, j + 1, r);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }
    q_sort(q, 0, n - 1);
    for (int i = 0; i < n;i++){
        printf("%d", q[i]);
        if(i!=n-1)
            printf(" ");
    }
        return 0;
}