#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
理解题意，多个哈希表记录数字出现，差值
*/
int vis[110000]={0};//已经有的数字
int g[10][1000];
int dir[110000]={0};//已经有的差值
int kick[10]={0};
unordered_set<int> s;
int main()
{
    int a, b, n, m, cnt = 0;
    cin >> a >> b;
    cin >> n >> m;
    s.insert(a);
    s.insert(b);
    dir[abs(a - b)] = 1;
    vis[a] = vis[b] = 1;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    for (int j = 0; j < m;j++)
    {
        for (int i = 0; i < n;i++)
        {
            if(dir[g[i][j]]==1&&vis[g[i][j]]==0&&kick[i]==0)
            {
                //数字有效
                for(int e:s)
                {
                    dir[abs(e - g[i][j])] = 1;
                }
                s.insert(g[i][j]);
                vis[g[i][j]] = 1;
            }
            else
            {
                if(kick[i]==0)
                {
                    cnt++;
                    kick[i] = 1;
                    printf("Round #%d: %d is out.\n", j + 1, i + 1);
                }
            }
        }
    }
    if(cnt==n)
        cout << "No winner.\n"<<endl;
    else
    {
        printf("Winner(s):");
        for (int i = 0; i < n;i++)
        {
            if(kick[i]==0)
                cout << " " << i + 1;
        }
        cout << endl;
    }
    
        return 0;
}