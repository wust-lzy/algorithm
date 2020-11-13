#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=2019,m=324,sum=0,t;
    while(m)
    {
        sum+=n/m;
        t=m;
        m=n%m;
        n=t;
    }
    cout<<sum;
    return 0;
}

