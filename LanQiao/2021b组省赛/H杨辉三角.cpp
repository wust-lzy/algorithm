#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
int main()
{
    ll n;
    cin >> n;
    ll cnt = 2;
    if (n == 1)
        cout << 1;
    else
    {
        a.push_back(1); //第二层
        a.push_back(1); 
        while (1)
        {
            cnt++; //第cnt层
            vector<ll> temp(a); //复制上一份
            for (ll i = 1; i < cnt - 1; i++)
            {
                temp[i] = a[i] + a[i - 1];
                if (temp[i] == n) //找到了这个数
                {
                    ll ans = cnt* (cnt - 1) / 2;
                    ans += (1 + i);
                    cout << ans;
                    return 0;
                }
            }
            temp.push_back(1);  //末尾元素
            a = temp;
        }
    }
    return 0;
}