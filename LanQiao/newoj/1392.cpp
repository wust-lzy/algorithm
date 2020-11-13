#include<bits/stdc++.h>
using namespace std;
int vis[35];
long long ans=0;
void dfs(int n)
{
    if(n==30)//0~29共30盏灯
    {
        for(int i=1;i<30;i++)
        {
            if(vis[i-1]&&vis[i])
            return;
        }
        ans++;
        return;
    }
    vis[n]=1;
    dfs(n+1);
    vis[n]=0;//回溯
    dfs(n+1);
}
int main()
{
    //dfs(0);
    //cout<<ans;//2178309
    printf("%d",2178309);
    return 0;
}