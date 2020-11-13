#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int f1[N+1],f2[N+1],f3[N+1];//记录手机数为1,2,3,时 对应各层的测试次数
int main()
{
    //1部手机的情况
    for(int i=1;i<=N;i++)
    {
        f1[i]=i;
    }
    //2部手机的情况
    for(int i=1;i<=N;i++)
    {
        int ans=INT_MAX;
        //尝试1~i若干种方案，最终记录所有方案中次数最小的
        for(int j=1;j<=i;j++)//在j层扔第一个手机
        {
            //好的  或者  砸坏了
            int _max=1+max(f2[i-j],f1[j-1]);
            ans=min(_max,ans);
        }
        f2[i]=ans;
    }
    //3部手机的情况
    for(int i=1;i<=N;i++)
    {
        int ans=INT_MAX;
        //尝试1~i若干种方案，最终记录所有方案中次数最小的
        for(int j=1;j<=i;j++)//在j层扔第一个手机
        {
            //好的  或者  砸坏了
            int _max=1+max(f3[i-j],f2[j-1]);
            ans=min(_max,ans);
        }
        f3[i]=ans;
    }
    cout<<f3[N]<<endl;
    return 0;
}
