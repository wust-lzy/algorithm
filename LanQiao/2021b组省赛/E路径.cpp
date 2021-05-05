#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e12;
int vis[2050];
ll e[2050][2050], dis[2050];
ll gcd(ll a,ll b)   //求最大公因数
{
    return a % b == 0 ? b : gcd(b, a % b);
}
ll lcm(ll a,ll b)   //求最小公倍数
{
    return a * b / gcd(a, b);
}
int main()
{
    fill(dis, dis + 2050, inf);
    fill(e[0], e[0] + 2050 * 2050, inf);
    for (int i = 1; i <= 2021;i++)
    {
        for (int j = 1; j <= 21;j++)    //21步以内有效
        {
            int k = i + j;  //i为起点，k为终点
            if(k>2021)
                break;
            e[i][k] = e[k][i] = lcm(i, k);
        }   
    }
    dis[1] = 0;
    //最短路径模板  dijstra算法
    for (int i = 1; i <= 2021;i++)
    {
        ll u = -1, minn = inf;
        for (int j = 1; j <= 2021;j++)//找到起点
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn = dis[j];
                u = j;
            }
        }
        if(u==-1)
            break;
        vis[u] = 1;
        for (int v = 1; v <= 2021;v++)
        {
            if(!vis[v])
                dis[v] = min(dis[v], e[u][v] + dis[u]);
        }
    }
    cout << dis[2021];
    return 0;
}