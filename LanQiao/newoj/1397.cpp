#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
int a[9]={1,2,3,4,5,6,7,8,9};
bool ok(ll t)
{
    if(t<100000000||t>=1000000000)  return 0;
    int a[10]={0};
    while(t)
    {
        a[t%10]++;
        t/=10;
    }
    for(int i=1;i<10;i++)
        if(!a[i])
        return 0;
    return 1;
}
void dfs(int l,int r,int cnt)
{
    if(cnt==9){
        if(l*r>ans){
            if(ok(l*r)){
                ans=l*r;
            }
        }
        return;
    }
    dfs(l*10+a[cnt],r,cnt+1);
    dfs(l,r*10+a[cnt],cnt+1);
}
int main()
{
    /*do
    {
        dfs(0,0,0);
    } while (next_permutation(a,a+9)); 839542176  */ 
    cout<<839542176;
    return 0;
}