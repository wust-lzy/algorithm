#include <bits/stdc++.h>
using namespace std;
int cnt1=0,cnt2=0;
int main()
{
    int t;
    for(int i=0;i<100;i++)
    {
        cin>>t;
        while(t%5==0)
        {
            cnt1++;
            t/=5;
        }
        while(t%2==0)
        {
            cnt2++;
            t/=2;
        }
    }
    cout<<min(cnt1,cnt2);
    //cout<<31;
    return 0;
}

