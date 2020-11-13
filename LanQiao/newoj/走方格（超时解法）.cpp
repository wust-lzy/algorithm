#include<bits/stdc++.h>
using namespace std;
int n,m,dir[2][2]={{0,1},{1,0}};
long long ans=0;
struct Point
{
    int x,y;
    Point(int i,int j):x(i),y(j){}
};

bool check(int i,int j)
{
    if((1&i)==0&&(1&j)==0)
      return 0;
    return i>=1&&i<=n&&j>=1&&j<=m;
}

void bfs()
{
    queue<Point> q;
    q.push(Point(1,1));
    while(!q.empty())
    {
        Point f=q.front();
        q.pop();
        if(f.x==n&&f.y==m)
        {
            ans++;
        }
        for(int i=0;i<2;i++)
        {
            int dx=f.x+dir[i][0];
            int dy=f.y+dir[i][1];
            if(check(dx,dy))
            {
                q.push(Point(dx,dy));
            }
        }
    }
}
int main()
{
    /*cout<<(1&1)<<endl;
    cout<<(1&2)<<endl;
    cout<<(1&3)<<endl;
    cout<<(1&4)<<endl;
    cout<<(1&5)<<endl;*/
    cin>>n>>m;
    bfs();
    cout<<ans;
    return 0;
}