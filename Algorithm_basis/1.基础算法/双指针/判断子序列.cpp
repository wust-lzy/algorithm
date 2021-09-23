#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N], b[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < m;i++)
        scanf("%d", &a[i]);
    int i = 0, j = 0;
    while(i<n&&j<m){
        if(b[i]==a[j++])
            i++;
    }
    printf("%s", i ==n ? "Yes" : "No");
    return 0;
}