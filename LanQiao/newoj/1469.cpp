#include<bits/stdc++.h>
using namespace std;
bool check(int n){
    while(n){
        if(n%10==2||n%10==0||n%10==1||n%10==9)      return 1;
        n/=10;
    }
    return 0;
}
int main()
{
    long long ans=0;
    for(long long i=1;i<=2019;i++){
        if(check(i)){
            ans+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}