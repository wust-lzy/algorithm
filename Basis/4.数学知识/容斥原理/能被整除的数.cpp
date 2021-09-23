#include <iostream>
#include <algorithm>
#include <cstring>
typedef long long ll;
using namespace std;

const int N = 20;
int p[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i];
    int ans = 0;
    for (int i = 1; i < 1 << m; i++) //每一个集合的状态
    {
        int t = 1, cnt = 0; //选中集合质数的乘积，集合元素的个数
        for (int j = 0; j < m; j++)
        {
            if (i >> j & 1) //选中一个集合
            {
                cnt++;
                if ((ll)t * p[j] > n)
                {
                    t = -1;
                    break;
                }
                t *= p[j];
            }
        }
        if (t != -1)
        {
            if (cnt & 1)//选中集合个数为奇数个 容斥原理  加上
                ans += n / t;
            else    //反之 减去
                ans -= n / t;
        }
    }
    cout << ans;
    return 0;
}