#include<bits/stdc++.h>
using namespace std;
int a[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
}; //数组记录12个月的天数  a[0][m]对应平年，a[1][m]对应闰年
int leapyear(int y)//判断闰年
{
    return y%4==0&&y%100!=0||y%400==0;
}
int days(int y,int m)//返回y年m月的天数
{
    return a[leapyear(y)][m];
}
bool check1(int n) //回文
{
    int sum=0,k=n;
    while(n)
    {
        sum*=10;
        sum+=n%10;
        n/=10;
    }
    return sum==k;
}
bool check2(int n)//ababbaba回文
{
    int w[8],k=7;
    while(n)
    {
        w[k--]=n%10;
        n/=10;
    }
    if(w[0]!=w[2]||w[0]!=w[5]||w[0]!=w[7]||w[0]==w[1])
    return 0;
    if(w[1]!=w[3]||w[1]!=w[4]||w[1]!=w[6])
    return 0;
    return 1;
}
int main()
{
    int n,y,m,d;
    int y1,m1,d1,y2,m2,d2;
    bool flag1=1,flag2=1;
    cin>>n;
    y=n/10000,m=n/100%100,d=n%100;
    while(flag1||flag2)
    {
        //日期处理
        d++;
        if(d>days(y,m))
        {
            d=1;
            m++;
        }
        if(m>12)
        {
            m=1;
            y++;
        }
        n=y*10000+m*100+d;
        if(check1(n)&&flag1)
        {
            y1=y;m1=m;d1=d;
            flag1=0;
        }
        if(check2(n)&&flag2)
        {
            y2=y;m2=m;d2=d;
            flag2=0;
        }

    }
    printf("%04d%02d%02d\n",y1,m1,d1);
    printf("%04d%02d%02d\n",y2,m2,d2);
    return 0;
}