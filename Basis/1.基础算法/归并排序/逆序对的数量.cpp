#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N], n;
int temp[N];
ll merge_sort(int l,int r){
    if(l>=r)
        return 0;
    int mid = l + r >> 1;
    ll ans = merge_sort(l, mid) + merge_sort(mid + 1, r);

    //归并
    int k = 0, i = l, j = mid + 1;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j])
            temp[k++] = a[i++];
        else{
            temp[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    //扫尾
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=r)
        temp[k++] = a[j++];
    //返回
    i=l,j=0;
    while(j<k)
        a[i++]=temp[j++];
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    cout << merge_sort(0, n - 1);
    return 0;
}