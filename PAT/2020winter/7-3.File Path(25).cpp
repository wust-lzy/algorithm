#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> book[10000];
int func(string t)
{
    int cnt = 0;
    while (t[cnt] == ' ')
        cnt++;
    return cnt;
}
int tonum(string t)
{
    int cnt = 0;
    while (t[cnt] == ' ')
        cnt++;
    return stoi(t.substr(cnt, 4));
}
vector<int> path,tempath;
void dfs(int st,int ed)
{
    tempath.push_back(st);
    if (st==ed)
    {
        path = tempath;
        return;
    }
    for (int i = 0; i < book[st].size();i++)
        dfs(book[st][i], ed);
    tempath.pop_back();
}
int main()
{
    unordered_map<int, int>vis;
    int n;
    cin >> n;
    getchar();
    vector<string> v(n);
    for (int i = 0; i < n;i++)//ok
    {
        getline(cin, v[i]);
        vis[tonum(v[i])] = 1;
    }
    // for (int i = 0; i < n;i++)//ok
    //     cout << func(v[i]) << "--" << tonum(v[i]) << endl;
    for (int i = 1; i < n;i++)
    {
        for (int j = i - 1; j >= 0;j--)
        {
            int a = func(v[i]);//当前字符串的空格数
            int b = func(v[j]);//寻找的字符串空格数
            if((a-b)==1) //相差为1
            {

                book[tonum(v[j])].push_back(tonum(v[i]));
                break;
            }
        }
    }
    int k;
    cin >> k;
    vector<int> q(k);
    for (int i = 0; i < k;i++)
        scanf("%d", &q[i]);
    for (int i = 0; i < k;i++)
    {
        int t = q[i];
        if(!vis[t])
            printf("Error: %04d is not found.\n",t);
        else
        {
            path.clear();
            tempath.clear();
            dfs(0, t);
            for (int i=0; i < path.size();i++)
            {
                printf("%04d", path[i]);
                if(i!=path.size()-1)
                    printf("->");
            }
            printf("\n");
        }
        
    }
    return 0;
}