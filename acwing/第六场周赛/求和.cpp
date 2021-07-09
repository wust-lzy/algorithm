#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;

using namespace std;
vector<ll> s;
void dfs(int u,ll x)
{
    s.emplace_back(x);
    if(u==10)
        return;
    dfs(u + 1, x * 10 + 4);
    dfs(u + 1, x * 10 + 7);
}
int main()
{
    dfs(0, 0);//预处理 ，存入所有的数
    sort(s.begin(), s.end());
    ll l, r, ans = 0;
    cin >> l >> r;
    for (int i = 1; i < s.size();i++)
    {
        ll a = s[i - 1]+1, b = s[i];//每个区间的左边界和右边界
        ans +=s[i] * max(0ll, (min(r, b) - max(l, a) + 1));
    }
    cout << ans;
    return 0;
}