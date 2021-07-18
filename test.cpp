#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

const int N=510,inf=1e8;
int e[N][N],dis[N];
int n,m;
bool vis[N];





int dijstra()
{
    fill(dis,dis+N,inf);
    dis[1]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=-1;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&((u==-1)||dis[u]>dis[j]))
                u=j;
        }
        if(u==-1)
            break;
        vis[u]=1;
        for(int v=1;v<=n;v++)
            dis[v]=min(dis[v],dis[u]+e[u][v]);
    }
    if(dis[n]==inf)
        return -1;
    return dis[n];
}




int main()
{
    fill(e[0],e[0]+N*N,inf);
    cin>>n>>m;
    while(m--)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        e[x][y]=min(e[x][y],z);
    }
    printf("%d\n",dijstra());
    return 0;
}