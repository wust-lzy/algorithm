#include <bits/stdc++.h>
using namespace std;
int e[210][210];
int n,m;
bool ok(vector<int>&temp)//≈–∂œ¡¨Õ®–‘
{
    for(int i=0;i<temp.size();i++)
    {
        for(int j=i+1;j<temp.size();j++)
        {
            if(!e[temp[i]][temp[j]])
                return 0;
        }
    }
    return 1;
}
int func(vector<int>&temp,int vis[])
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vector<int>t=temp;
            t.push_back(i);
            if(ok(t))
                return i;
        }
    }
    return -1;
}
int main()
{
    memset(e,0,sizeof(e));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        e[a][b]=e[b][a]=1;
    }
    int k,l;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&l);
        vector<int>temp(l);
        int vis[n+1]={0};
        for(int j=0;j<l;j++)
        {
            scanf("%d",&temp[j]);
            vis[temp[j]]=1;
        }
        if(!ok(temp))
            printf("Area %d needs help.\n",i);
        else
        {
            int small=func(temp,vis);
            if(small==-1)
                printf("Area %d is OK.\n",i);
            else
                printf("Area %d may invite more people, such as %d.\n",i,small);
        }
    }
	return 0;
}

