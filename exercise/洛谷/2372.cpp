#include<bits/stdc++.h>
using namespace std;
bool vis[25][25];
int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};//上下左右对角
int m,n,x,y;
char mp[25][25];
void bfs(int x,int y)
{
    queue<pair<int,int> > q;
    vis[x][y]=1;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pair<int,int>p=q.front();
        q.pop();
        vis[p.first][p.second]=1;
        for(int i=0;i<8;i++)
        {
            int dx=p.first+dir[i][0];
            int dy=p.second+dir[i][1];
            if(dx>=1&&dx<=m&&dy>=1&&dy<=n&&!vis[dx][dy]&&mp[dx][dy]=='X')
            q.push(make_pair(dx,dy));
        }
    }
}
int main()
{
    int i,j,ans=0;
    cin>>m>>n>>x>>y;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    cin>>mp[i][j];
    bfs(x,y);
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++){
        if(vis[i][j]){
            for(int k=0;k<4;k++){
                int dx=i+dir[k][0];
                int dy=j+dir[k][1];
                if(!vis[dx][dy])
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
