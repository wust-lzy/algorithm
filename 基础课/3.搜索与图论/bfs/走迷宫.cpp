#include <iostream>
#include<queue>
using namespace std;

typedef pair<int, int> pii;//定义pair，寸坐标
int n, m;
const int N = 110;
int g[N][N], dis[N][N],vis[N][N];//图，到达每个点的距离，是否遍历过
const int go[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int bfs()
{
    queue<pii> q;
    vis[0][0] = 1;
    q.push(pii(0, 0));
    while(!q.empty()){
        pii temp = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int dx = temp.first + go[i][0];
            int dy = temp.second + go[i][1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&!vis[dx][dy]&&g[dx][dy]==0){
                vis[dx][dy]=1;//标记已经遍历
                dis[dx][dy] = dis[temp.first][temp.second] + 1;//距离+1
                q.push({dx, dy});//入队
            }
        }
    }
    return dis[n - 1][m - 1];
}
int main()
{
    cin>>n>>m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++)
            cin >> g[i][j];
    }
    cout << bfs();
    return 0;
}