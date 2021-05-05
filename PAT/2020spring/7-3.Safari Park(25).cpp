#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[505][505] = {0};
pair<int, int> p[1001];
int v[505];
int n, r, k, m;
bool ok()
{
    for (int i = 0; i < r; i++)
        if (v[p[i].first] == v[p[i].second])
            return 0;
    return 1;
}
int main()
{
    cin >> n >> r >> k;
    for (int i = 0; i < r; i++)
    {
        scanf("%d %d", &p[i].first, &p[i].second);
        // int a, b;
        // scanf("%d %d", &a, &b);
        // g[a][b] = g[b][a] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        unordered_set<int> cnt;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &v[j]);
            cnt.insert(v[j]);
        }
        if (cnt.size() != k)
        {
            if (cnt.size() > k)
                printf("Error: Too many species.\n");
            else if (cnt.size() < k)
                printf("Error: Too few species.\n");
        }
        else
        {
            if (ok())
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}