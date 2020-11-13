#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[10005],i,cnt1=0,cnt2=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=60) cnt1++;
        if(a[i]>=85) cnt2++;
    }
    double ans1=cnt1*1.0/(n*1.0);
    double ans2=cnt2*1.0/(n*1.0);
    cout<<(int)((ans1+0.005)*100)<<"%"<<endl;
    cout<<(int)((ans2+0.005)*100)<<"%"<<endl;
    return 0;
}