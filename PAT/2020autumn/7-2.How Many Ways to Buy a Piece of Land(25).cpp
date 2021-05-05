#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n;i++)
        scanf("%d", &v[i]);
    int cnt = 0;
    for (int i = 0; i < n;i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            if(sum<=m)
                cnt++;
            else
                break;
        }
    }
    cout << cnt;
    return 0;
}