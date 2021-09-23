#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, x;
int a[N], b[N];
int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m;i++)
        scanf("%d", &b[i]);
    int i = 0, j = m - 1;
    while(a[i]+b[j]!=x){
        int sum = a[i] + b[j];
        if(sum<x)
            i++;
        else
            j--;
    }
    cout << i << " " << j;
    return 0;
}