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
    int ans = 0;
    unordered_map<int, int> cnt;
    for (int i = 0, j = 0; j < n;j++){
        cnt[a[j]]++;
        while(cnt[a[j]]==2)
            cnt[a[i++]]--;
        ans = max(ans, j - i + 1);
    }
    cout << ans;
    return 0;
}