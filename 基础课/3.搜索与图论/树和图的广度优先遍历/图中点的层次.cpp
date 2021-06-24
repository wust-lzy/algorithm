#include <iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int dis[N];
int n, m; //点，边
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs()
{
    queue<int> q;
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    q.push(1);//起点为1
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for (int i = h[temp]; i != -1;i=ne[i])//遍历当前节点所有子结点
        {
            int j = e[i];
            if(dis[j]==-1)
            {
                dis[j] = dis[temp] + 1;
                q.push(j);
            }
        }
    }
    return dis[n];
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m;i++){//有向图
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
    }
    cout << bfs();
    return 0;
}