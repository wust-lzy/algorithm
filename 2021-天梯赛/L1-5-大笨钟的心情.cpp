#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[24];
    for (int i = 0; i < 24;i++)
        cin >> a[i];
    int t;
    while (cin >> t)
    {
        if(t<0||t>23)
            break;
        printf("%d %s\n",a[t],a[t]>50?"Yes":"No");
    }
    return 0;
}