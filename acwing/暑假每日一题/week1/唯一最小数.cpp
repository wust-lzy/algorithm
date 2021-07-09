#include <iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int maxn = 1e7, ans = -1;
        int n;
        scanf("%d", &n);
        unordered_map<int, int> vis;
        for (int i = 1; i <= n;i++)
        {
            scanf("%d", &a[i]);
            vis[a[i]]++;
        }
        for (int i = 1; i <= n;i++)
        {
            if(vis[a[i]]==1)
            {
                if(a[i]<maxn)
                {
                    maxn = a[i];
                    ans = i;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}