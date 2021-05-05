#include<bits/stdc++.h>
using namespace std;
int ans=0;
void f(int n)
{
    while(n)
    {
        if(n%10==2)
        ans++;
        n/=10;
    }
}
int main()
{
    for(int i=1;i<=2020;i++)
    f(i);
    cout<<ans;
    return 0;
}