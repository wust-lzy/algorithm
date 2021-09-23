#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int a[N];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    while(q--){
        int k;
        scanf("%d", &k);
        int l = 0, r = n - 1;
        while(l<r){
            int mid = l + r >> 1;
            if(a[mid]>=k)
                r = mid;
            else
                l = mid + 1;
        }
        if(a[l]!=k)
        {
            printf("-1 -1\n");
            continue;
        }
        printf("%d ", l);
        l = 0, r = n - 1;
        while(l<r){
            int mid = l + r + 1 >> 1;
            if(a[mid]<=k)
                l = mid;
            else
                r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}