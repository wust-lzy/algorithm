#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long LL;

using namespace std;

const int N = 20,M=3010;
LL f[M];
int n,m;

int main()
{
    cin>>n>>m;
    f[0]=1;
    for (int i = 0; i < n; i ++ )//完全背包
    {
        int v;
        cin>>v;
        for (int j = v; j <= m; j ++ )
            f[j]+=f[j-v];
    }
    cout<<f[m];
    return 0;
}