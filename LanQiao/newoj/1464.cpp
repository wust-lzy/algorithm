#include<bits/stdc++.h>
using namespace std;
int ans=0;
bool check(int i){
    while(i){
        if(i%10==2||i%10==4)
        return 0;
        i/=10;
    }
    return 1;
}
void dfs(int x,int left,int t)
{
    if(t==1){
        if(check(left)&&left>x){
            ans++;
            return;
        }
        return;
    }
    for(int i=x+1;i<=left/t;i++){
        if(check(i)){
            dfs(i,left-i,t-1);
        }
    }
}
int main()
{
    dfs(0,2019,3);
    cout<<ans;
    return 0;
}