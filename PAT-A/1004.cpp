#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v[105];
int maxdepth = -1,num[100];
void dfs(int index,int depth)
{
    if(!v[index].size())
    {
        maxdepth = max(maxdepth, depth);
        num[depth]++;
        return;
    }
    for (int i = 0; i < v[index].size();i++)
        dfs(v[index][i], depth + 1);
}
int main()
{
    int n, m ; //总节点数，非叶子节点数
    cin >> n >> m;
    for (int i = 0; i < m;i++)
    {
        int node, k, son;
        cin >> node >> k;
        for (int j = 0; j < k;j++)
        {
            cin >> son;
            v[node].push_back(son);
        }
    }
    dfs(1, 0);
    cout << num[0];
    for (int i = 1; i <= maxdepth;i++)
        cout << " " << num[i];
    return 0;
}
