#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 110;
int a[N];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        bool flag = true;
        sort(a, a + n);
        for (int i = 1; i < n;i++)
            if((a[i]-a[0])&1)
                {
                    flag = false;
                    break;
                }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}