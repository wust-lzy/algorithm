#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], f1[N], f2[N];
int n;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n;i++)//最长上升，或者最长下降
        {
            cin >> a[i];
            f1[i] = f2[i] = 1;
            for (int j = 0; j < i;j++){
                if(a[i]<a[j]&&f1[i]<f1[j]+1)
                    f1[i] = f1[j] + 1;
                if(a[i]>a[j]&&f2[i]<f2[j]+1)
                    f2[i] = f2[j] + 1;
            }
            ans = max(ans, f2[i]);
            ans = max(ans, f1[i]);
        }
        cout << ans << endl;
    }
    return 0;
}