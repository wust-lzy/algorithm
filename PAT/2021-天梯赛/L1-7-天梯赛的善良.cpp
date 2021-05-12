#include<bits/stdc++.h>
using namespace std;
const int inf = 1e7;
int a[inf + 5];
int main()
{
    int n;
    cin >> n;
    int minn = inf, maxn = -1;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i]<minn)
        {
            cnt1 = 1;
            minn = a[i];
        }
        else if(a[i]==minn)
            cnt1++;


        if(a[i]>maxn)
        {
            cnt2 = 1;
            maxn = a[i];
        }
        else if(a[i]==maxn)
            cnt2++;
    }
    cout << minn << " " << cnt1 << endl;
    cout << maxn << " " << cnt2;
    return 0;
}