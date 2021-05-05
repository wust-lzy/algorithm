#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int a[105][105],i,j,cnt=1;
    for(i=1;i<=100;i++)//分为奇数行和偶数行讨论
    {
        if(i%2)//奇数行 从左到右
        {
            for(j=1;j<=i;j++)
            a[j][i+1-j]=cnt++;
        }
        else//偶数行  从右到左
        {
            for(j=i;j>=1;j--)
            a[j][i+1-j]=cnt++;
        }
    }
    cout<<a[20][20];
    return 0;
}