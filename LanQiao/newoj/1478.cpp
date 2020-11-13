#include<bits/stdc++.h>
using namespace std;
int main()
{
    double ans=0.61803399;
    int i,n;
    long long f[1000];
    f[1]=1;
    f[2]=1;
    for(i=3;i<=50;i++){
        f[i]=f[i-1]+f[i-2];
        //printf("%.8lf\n",f[i-1]*1.0/f[i]);
    }
    cin>>n;
    if(n<=35)  printf("%.8lf",f[n]*1.0/f[n+1]);
    else  printf("%.8lf",ans);
    return 0;
}