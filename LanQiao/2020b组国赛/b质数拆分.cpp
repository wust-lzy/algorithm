#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2019;
vector<int> prime;
ll dp[2050];
void work() //素数筛
{
    bool vis[2050];
    memset(vis, 0, sizeof(vis));
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= N;i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
            for (int j = 2 * i; j <= N;j+=i)
                vis[j] = 1;
        }
    }
}
int main()
{
    work();
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < prime.size();i++)
    {
        for (int j = 2019; j >= prime[i];j--)
        {
            //cout << j << endl;
            dp[j] += dp[j - prime[i]];
        } 
    }
    printf("%lld\n",dp[2019]);
    return 0;
}