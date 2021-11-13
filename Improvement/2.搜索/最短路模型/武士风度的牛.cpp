#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;
typedef pair<int, int> pii;
int st, ed;

int op(int x, int idx)
{
    if (idx == 0)
        return x - 1;
    if (idx == 1)
        return x + 1;
    return 2 * x;
}
int bfs()
{
    unordered_set<int> vis;
    queue<pii> q;
    q.push(pii(st, 0));
    vis.insert(st);
    while (!q.empty())
    {
        pii t = q.front();
        q.pop();
        if (t.first == ed)
            return t.second;
        for (int i = 0; i < 3; i++)
        {
            int go = op(t.first, i);
            if (go >= 0 && go <= 1e5 && !vis.count(go))
            {
                vis.insert(go);
                q.push(pii(go, t.second + 1));
            }
        }
    }
    return -1;
}
int main()
{
    cin >> st >> ed;
    cout << bfs();
    return 0;
}