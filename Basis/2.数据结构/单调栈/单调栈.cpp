#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int stk[N], tt;
int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &x);
        while(tt&&stk[tt]>=x)//如果栈顶元素大于当前待入栈元素，则出栈
            --tt;
        if(tt)
            printf("%d ", stk[tt]);//栈顶元素就是比当前元素小的
        else
            printf("-1\n");//如果栈空，则没有比该元素小的值。
        stk[++tt] = x;
    }
    return 0;
}