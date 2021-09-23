#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int prime[N], vis[N], cnt;

void divide(int x)//埃及筛法  好写
{
    for (int i = 2; i <= x;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            prime[cnt++] = i;
            for (int j = i + i; j <= x;j+=i)
                vis[j] = 1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    divide(n);
    cout << cnt;
    return 0;
}