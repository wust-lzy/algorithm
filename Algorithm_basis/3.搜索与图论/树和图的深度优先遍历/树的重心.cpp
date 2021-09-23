#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100010;//数据范围1e5
const int M = N * 2;//无向图 一个点最多2n-2条边
int n;
int h[N], e[M], ne[M], idx;//领结表存储树 h[i]是队列头节点 e[i]存储元素 ne[i]存储列表next值
bool st[N];//记录是否访问过
int ans = N;
//a所对应的单链表中插入b  a作为根
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
//以u为根的子树点的数量
int dfs(int u){
    st[u] = true;//已经搜过
    int sum = 1;//以u为根的子树节点的个数
    int res = 0;//删除某个节点后 最大的连通子图节点的个数
    //访问u的每个子结点
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];//下一结点
        if(!st[j])//没有搜过
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}
int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n-1;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1);//可选择任意一个节点开始
    printf("%d\n", ans);
    return 0;
}