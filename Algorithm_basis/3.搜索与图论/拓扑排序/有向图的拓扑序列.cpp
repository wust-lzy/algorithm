#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N],e[N],ne[N],idx;
int dis[N], q[N];

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort(){
    int hh = 0, tt = -1;
    for (int i = 1; i <= n;i++){//所有入度为0的点入队
        if(!dis[i])
            q[++tt]=i;
    }
    while(hh<=tt){
        int t = q[hh++];//队头结点出队
        for (int i = h[t]; i != -1;i=ne[i]){
            int j = e[i];
            dis[j]--;   //下一个结点的入度-1
            if(dis[j]==0) //如果下一个结点的入度也为0，继续入队
                q[++tt]=j;
        }
    }
    return tt == n - 1;//队头的个数是不是等于n 因为tt从-1开始
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
        dis[b]++;//入度加一
    }
    if(topsort()){
        for (int i = 0; i < n;i++)
            printf("%d ", q[i]);
    }
    else
        cout << -1;
    return 0;
}