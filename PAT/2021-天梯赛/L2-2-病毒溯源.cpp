#include <bits/stdc++.h>
using namespace std;
int max_dep = -1;
vector<int> temp, ans;
vector<int> v[10005];
int father[10005];
void dfs(int index, int depth)
{
    temp.push_back(index);
    if (v[index].empty())
    {
        if (depth > max_dep)
        {
            ans = temp;
            max_dep = depth;
        }
        temp.pop_back();
        return;
    }
    int len = v[index].size();
    for (int i = 0; i < len; i++)
        dfs(v[index][i], depth + 1);
    temp.pop_back();
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k, temp;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &temp);
            v[i].push_back(temp);
            father[temp] = 1;
        }
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < n; i++)
    {
        if(!father[i]){ //没有父节点  找到源点
            temp.clear();
            dfs(i, 1);
            break;
        }
    }
    printf("%d\n", max_dep);
    int len = ans.size();
    for (int i = 0; i < len; i++)
    {
        printf("%d", ans[i]);
        if (i != len - 1)
            printf(" ");
    }
    return 0;
}
