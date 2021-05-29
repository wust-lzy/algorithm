#include<bits/stdc++.h>
using namespace std;
char g[105][105];
int vis[105][105];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
struct Point
{
    int x,y;
    Point(int i,int j):x(i),y(j){}
};
void bfs(int i,int j)
{
    vis[i][j]=1;
    queue<Point>q;
    q.push(Point(i,j));
    while(!q.empty())
    {
        Point f=q.front();
        q.pop();
        int xx=f.x,yy=f.y;
        vis[xx][yy]=1;
        for(int k=0;k<4;k++){
            int dx=xx+dir[k][0];
            int dy=yy+dir[k][1];
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&!vis[dx][dy]&&g[dx][dy]!='0'){
                q.push(Point(dx,dy));
            }
        }
    }
}
int main()
{
    int i,j,ans=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(!vis[i][j]&&g[i][j]!='0'){
                ans++;
                bfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}