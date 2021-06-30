#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 12, M = 1 << N;
long long f[N][M];
bool vis[M];
int main()
{
    int n, m;
    while(cin>>n>>m,n||m)
    {
        memset(f, 0, sizeof f);
        for (int i = 0; i < 1 << n;i++)
        {
            vis[i] = true;
            int cnt = 0;//统计竖着为0的个数
            for (int j = 0; j < n;j++)
            {
                if(i>>j&1)
                {
                    if(cnt&1)//连续空格数为奇数 不行
                    {
                        vis[i] = false;
                        break;
                    }
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                vis[i] = false;
        }
        f[0][0] = 1;
        for (int i = 1; i <= m;i++)//状态转移
            for (int j = 0; j < 1 << n;j++)
                for (int k = 0; k < 1 << n;k++)
                if( (j&k)==0 && vis[j|k])
                    f[i][j] += f[i - 1][k];
        cout << f[m][0] << endl;
    }
    return 0;
}