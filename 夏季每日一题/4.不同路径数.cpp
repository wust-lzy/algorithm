#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
int a[20][20];
int go[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
vector<int> temp;
set<string> s;
void dfs(int now,int x,int y){
    temp.push_back(a[x][y]);
    if(now==k)
    {
        string ans = "";
        for (int i = 0; i < temp.size();i++){
            ans += temp[i] + '0';
        }
        s.insert(ans);
        temp.pop_back();
        return;
    }
    for (int i = 0; i < 4;i++){
        int dx = x + go[i][0];
        int dy = y + go[i][1];
        if(dx>=0&&dx<n&&dy>=0&&dy<m&&now<k)
            dfs(now + 1, dx, dy);
    }
    temp.pop_back();
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            dfs(0, i, j);
    cout << s.size();
    return 0;
}