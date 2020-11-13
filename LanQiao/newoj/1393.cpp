#include<bits/stdc++.h>
using namespace std;
const int N=1e+5;
int n,k,cnt[N],vis[N];
void bfs()
{
    vis[0]=1;
    queue<pair<int,int> >q;
    q.push(make_pair(0,0));
    int go;
    while(!q.empty())
    {
        pair<int,int> x=q.front();
        q.pop();
        go=(x.first+1)%n;
        if(!vis[go]){
            vis[go]=1;
            cnt[go]=x.second+1;
            q.push(make_pair(go,x.second+1));
        }
        go=(x.first+k)%n;
        if(!vis[go]){
            vis[go]=1;
            cnt[go]=x.second+1;
            q.push(make_pair(go,x.second+1));
        }
    }
}
int main()
{
    int i,ans=0;
    cin>>n>>k;
    bfs();
    for(i=0;i<n;i++)
    ans=max(ans,cnt[i]);
    cout<<ans;
    return 0;
}