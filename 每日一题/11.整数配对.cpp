#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    ll sum = 0;
    for (int i = 0; i < n;i+=2){
        sum += a[i + 1] - a[i];
    }
    cout << sum;
    return 0;
}