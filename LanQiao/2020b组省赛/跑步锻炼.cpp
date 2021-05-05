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
int main()
{
    int y=2000,m=1,d=1,week=6,cnt=0;
    bool flag=1;
    while(flag)
    {
        if(y==2020&&m==10&&d==1)
        flag=0;

        cnt++;//跑一千米
        if(d==1||week==1)
        cnt++;//额外跑一千米
        //日期处理
        week=week==7?1:(week+1);
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
    }
    cout<<cnt;
    return 0;
}