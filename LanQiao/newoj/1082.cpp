#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll add(ll m,ll n)
{
    return (m+n)*(n-m+1)/2;
}
int divide(ll num)
{
    ll i=1,j=2,cnt=0;
    ll sum=0;
    while(i<=num/2)
    {
        sum=add(i,j);
        while(sum!=num)
        {
            if(sum>num)
                i++;
            else
                j++;
            sum=add(i,j);
        }
        if(i<j)
        cnt++;
        //cout<<i<<" "<<j<<endl;
        i++;
    }
    return cnt;
}
 
int main()
{
    ll num;
    while(cin>>num)
    {
        cout<<divide(num)<<endl;        
    } 
    return 0;
}