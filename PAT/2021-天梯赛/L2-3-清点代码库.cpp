#include <bits/stdc++.h>
using namespace std;
struct node
{
    int cnt;
    vector<int> val;
};
vector<node> ans;
map<vector<int>, int> vis;
int n, m;
bool cmp(node &a, node &b)
{
    if (a.cnt != b.cnt)
        return a.cnt > b.cnt;
    else
    {
        for (int i = 0; i < a.val.size(); i++)
        {
            if (a.val[i] != b.val[i])
                return a.val[i] < b.val[i];
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        vector<int> v(m);
        for (int j = 0; j < m; j++)
            scanf("%d", &v[j]);
        vis[v]++;
    }
    for(auto it:vis)
        ans.push_back({it.second, it.first});
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d", ans[i].cnt);
        for (int j = 0; j < ans[i].val.size(); j++)
            printf(" %d", ans[i].val[j]);
        printf("\n");
    }
    return 0;
}