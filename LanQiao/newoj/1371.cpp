#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005],mid[100005];
int main()
{
    //开long long！！！！
    long long i,j,n,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];
    for(i=0;i<n;i++)
        cin>>c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    i=j=n-1;
    while(i>=0&&j>=0)//记录b[j]比a[i]大的个数
    {
        if(a[i]<b[j])
        {
            mid[j]=i+1;
            j--;
        }
        else
        {
            i--;
        }
    }
    i=j=0;
    while(i<n&&j<n)
    {
        if(b[i]<c[j])
        {
            ans+=(n-j)*mid[i];
            i++;
        }
        else
        {
            j++;
        }
    }
    cout<<ans;
    return 0;
}
