#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;
int n;
int main()
{
    scanf("%d", &n);
    ll positive = 0, nagetive = 0;//乘积为正数和负数的前缀和
    int sp = 1, sn = 0, s = 1;//从1开始到n正数和负数的个数
    while(n--)//前缀和
    {
        int a;
        scanf("%d", &a);
        if(a<0)
            s *= -1;
        if(s>0)//当前s为正数，找到前面正数的个数加到postitive
            positive += sp, nagetive += sn, sp++;
        else//同理
            nagetive += sp, positive += sn, sn++;
    }
    cout << nagetive << " " << positive << endl;
    return 0;
}