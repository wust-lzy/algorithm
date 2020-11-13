#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn],f[maxn];
int Find(int x)
{
	return f[x]=f[x]==x?x:Find(f[x]);
}
int main()
{
	for(int i=1;i<maxn;i++)
    f[i]=i;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int root=Find(a[i]);
        a[i]=root;
        f[a[i]]=Find(a[i]+1);
    }
    for(int i=1;i<=n;i++){
        if(i>1) cout<<" ";
        cout<<a[i];
    }
	return 0;
}