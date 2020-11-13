#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main()
{
    int a=1,b=1,c=1;
    for(int i=4;i<=20190324;i++)
    {
        int t=a+b+c;
        t%=10000;
        a=b;
        b=c;
        c=t;
    }
    cout<<c;
    return 0;
}

