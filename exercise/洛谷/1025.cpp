#include<bits/stdc++.h>
using namespace std;
int ans=0;
void dfs(int x,int l,int t)
{
    if(t==1){
        ans++;
        return;
    }
    for(int i=x;i<=l/t;i++)
    dfs(i,l-i,t-1);
}
int main()
{
    int n,k;
    cin>>n>>k;
    dfs(1,n,k);
    cout<<ans;
    return 0;
}