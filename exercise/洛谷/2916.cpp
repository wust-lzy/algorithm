#include<bits/stdc++.h>
using namespace std;
int n,a[25][25];
int f[25],w[25],q[25],ans[25];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&w[i]);f[i]=w[i];}
	for(int i=1;i<=n-1;i++)
	for(int j=i+1;j<=n;j++)
	scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[j][i])
			{
				if(f[j]+w[i]>f[i])
				{
				    f[i]=f[j]+w[i];
				    q[i]=j;
				}
			}
		}
	}
	int x=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		if(f[x]<f[i])x=i;
	}
	ans[0]=f[x];
	while(x)
	{	
		ans[++tot]=x;
		x=q[x];
	}
	for(int i=tot;i>1;i--)printf("%d ",ans[i]);
	printf("%d",ans[1]);
	printf("\n%d",ans[0]);
	return 0;
}