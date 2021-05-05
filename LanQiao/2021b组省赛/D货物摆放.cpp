#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll n = 2021041820210418;
int main()
{
    set<ll> fac; //存放因子
    for (int i = 1; i <= sqrt(n);i++)
    {
        if(n%i==0)
        {
            fac.insert(i);
            fac.insert(n / i);
        }
    }
    vector<ll> v;  //  转存到数组里面，方便操作
    for(ll e:fac)   //foreach遍历
        v.push_back(e);
    int len = v.size();
    int cnt = 0;
    for (int i = 0; i < len;i++) //三重循环，枚举因子数乘积
        for (int j = 0; j < len;j++)
            for (int k = 0; k < len;k++)
            {
                if(v[i]*v[j]*v[k]==n)
                    cnt++;
            }
    cout << cnt;
    return 0;
}