#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
const int N = 510;
int ans[N][N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        unordered_map<int, pii> vis; //因为每个数只出现一次，用哈希表存储每个数的坐标
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int y;
                scanf("%d", &y);
                vis[y].second = j;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                scanf("%d", &x);
                vis[x].first = j;
            }
        }
        for (pair<const int,pii> &e : vis)
            ans[e.second.first][e.second.second] = e.first;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%d ", ans[i][j]);
            puts("");
        }
    }
    return 0;
}