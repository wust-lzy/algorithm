#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7; //n分解质因数 n=p1^a1 * p2^a2 * ... pk^ak
//约数的定义 p1^a1的约数有 p1^0,p1^1....p1^a1 共a1+1个
//所以n全部约数的个数为 (a1+1)*(a2+1)*....*(an+1)
//p1^a1的约数之和为 p1^0+p1^1+p1^2+...+p1^a1
//所有的约数之和为每个和相乘
int main()
{
    int n;
    cin >> n;
    long long ans = 1;
    unordered_map<int, int> primes; //每个质数的指数
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {

            while (x % i == 0)
            {
                x /= i;
                primes[i]++;//每个质因数的次数+1
            }
        }
        if (x > 1)//x的最大公约数可能大于根号x
            primes[x]++;
    }
    for (auto p : primes) //每个质因子的次数加1  求积
    {
        int t= p.second;
        long long temp = 1;
        while (t--) //求p1^0+p1^1+p1^2+...+p1^a1
            temp = (temp * p.first + 1)%mod;
        ans = ans * temp % mod;
    }
    cout << ans;
    return 0;
}