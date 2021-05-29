#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
bool dfs(int l,int r,int num)
{
    if(l>=r)
        return 1;
    if(s[l]==s[r])
        return dfs(l + 1, r - 1, num);
    if(num>=2)
        return 0;
    return dfs(l + 1, r, num + 1) || dfs(l, r-1, num + 1);
}
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        printf("%s\n", dfs(0,n-1,0)? "Yes" : "No");
    }
    return 0;
}