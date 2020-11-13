#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
const char dir[5]={'D','L','R','U'};
int maze[40][60];
struct point
{
    int x,y;
    string ans;
    point(int a,int b,string c):x(a),y(b),ans(c){}
};
bool judge(int x,int y)
{
    if(x>0&&x<=30&&y>0&&y<=50&&!maze[x][y])
        return true;
    return false;
}
void bfs()
{
    queue<point>ans;
    ans.push(point(1,1,""));
    maze[1][1]=1;
    while(!ans.empty())
    {
        point temp=ans.front();
        ans.pop();
        if(temp.x==30&&temp.y==50)
        {
            cout<<temp.ans<<endl;
            return ;
        }
        for(int i=0;i<4;i++)
        {
            int ax=temp.x+dx[i];
            int ay=temp.y+dy[i];
            if(judge(ax,ay))
            {
                maze[ax][ay]=1;
                ans.push(point(ax,ay,temp.ans+dir[i]));
            }
        }
    }
}
int main()
{
    freopen("C:\\Users\\Zzy\\Desktop\\新建文本文档.txt","r",stdin);
    for(int i=1;i<=30;i++)
        for(int j=1;j<=50;j++) {
            char t;
            cin>>t;
            maze[i][j]=t-'0';
        }
    bfs();
    return 0;
}

