#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans = 0;
int vis[30];//记录开灯情况
void dfs(int cnt)
{
    if (cnt == 30) //0~29共30盏灯
    {
        for (int i = 0; i < 29; i++)
        {
            if (vis[i] && vis[i + 1])  //连续两盏灯开不行
                return;
        }
        ans++;
        return;
    }
    vis[cnt] = 1;//点亮第cnt盏灯
    dfs(cnt + 1);

    vis[cnt] = 0;//不点亮
    dfs(cnt + 1);
}
int main()
{
    //dfs(0);
    //cout << ans;  2178309
    cout << 2178309;
    return 0;
}