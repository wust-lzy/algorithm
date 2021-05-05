#include <bits/stdc++.h>
using namespace std;
int a[10];
bool ok(int x)  //每个数消耗卡片
{
    while(x)
    {
        int temp = x % 10;
        if(a[temp])
        {
            a[temp]--;
            x /= 10;
        }
        else
            return 0;
    }
    return 1;
}
int main()
{
    fill(a, a + 10, 2021); //总共的卡片数
    for (int i = 1;; i++)
    {
        if(ok(i))
            continue;
        else
        {
            cout << i - 1;
            break;
        }
    }
        return 0;
}