#include<bits/stdc++.h>
using namespace std;
int dep[100005],a[100005];
int dfs(int now){
    int next=a[now];
    if(dep[next]){
        return dep[now]-dep[next]+1;
    }
    else
    {
        dep[next]=dep[now]+1;
        int ans=dfs(next);
        dep[next]=0;
        return ans;
    }
}
int main()
{
    int n,i,ans=-1;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(i=1;i<=n;i++)
    {
        dep[i]=1;//将i设置为起点
        int cnt=dfs(i);
        ans=max(cnt,ans);
        dep[i]=0;//回溯
    }
    cout<<ans;
    return 0;
}