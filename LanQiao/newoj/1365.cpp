#include<bits/stdc++.h>
using namespace std;
int n,ans=0,vis[1005][1005],dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char data[1005][1005];
struct Point
{
    int x,y;
    Point(int i,int j):x(i),y(j){}
};
bool inside(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<n;
}
void bfs(int i,int j)
{
    queue<Point>q;
    vis[i][j]=1;
    q.push(Point(i,j));
    int cnt1=0,cnt2=0;//cnt1记录一个连通块#的数量，cnt2记录旁边有.的数量的#的数量
    while(!q.empty())
    {
        Point first=q.front();
        q.pop();
        cnt1++;
        bool b=0;
        for(int k=0;k<4;k++)
        {
            int dx=first.x+dir[k][0];
            int dy=first.y+dir[k][1];
            if(inside(dx,dy)&&data[dx][dy]=='.') b=1;

            if(inside(dx,dy)&&data[dx][dy]=='#'&&!vis[dx][dy])
            {
                vis[dx][dy]=1;
                q.push(Point(dx,dy));
            }
        }
        if(b) cnt2++;
    }
    if(cnt1==cnt2)
        ans++;

}
int main()
{
    int i,j;
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
      {
        cin>>data[i][j];
      }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
      {
          if(!vis[i][j]&&data[i][j]=='#')
            bfs(i,j);
      }
    }
    cout<<ans<<endl;
    return 0;
}
