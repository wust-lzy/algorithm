#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    vector<int> rea;
    int pro;
};
vector<int> goods, products;
int n, m, k;
unordered_map<int, int> vis;
bool cmp(node a, node b)
{
    int len1 = a.rea.size(), len2 = b.rea.size();
    int index = 0;
    while (a.rea[index] == b.rea[index] && index < len1 && index < len2)
        index++;
    return a.rea[index] < b.rea[index];
}
bool ok(node a)
{
    for (int i = 0; i < a.rea.size(); i++)
        if (!vis[a.rea[i]])
            return 0;
    return 1;
}
int main()
{
    int temp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        goods.push_back(temp);
        vis[temp] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        products.push_back(temp);
    }
    cin >> k;
    vector<node> v;
    getchar();
    string s;
    for (int i = 0; i < k; i++)
    {
        getline(cin, s);
        node tt;
        tt.rea.push_back(stoi(s.substr(0, 2)));
        int index = 3;
        while (1)
        {
            if (s[index] == '+')
            {
                tt.rea.push_back(stoi(s.substr(index + 2, 2)));
                index += 4;
            }
            else if (s[index] == '-')
            {
                tt.pro = stoi(s.substr(index + 3, 2));
                break;
            }
            else
                index++;
        }
        v.push_back(tt);
    }
    // for (int i = 0; i < k;i++)  ok
    // {
    //     cout << v[i].pro << endl;
    //     for (int j = 0; j < v[i].rea.size();j++)
    //         cout << v[i].rea[j] << " ";
    //     cout << endl;
    // }
    for (int i = 0; i < m; i++)
    {
        vector<node> ans;
        for (int j = 0; j < k; j++)
        {
            if (v[j].pro == products[i]) //物料要足够才行
            {
                if (ok(v[j]))
                    ans.push_back(v[j]);
            }
        }
        if (ans.empty())
        {
            int cnt = 0,flag=0;
            for (int j = 0; j < goods.size(); j++)
            {
                if(vis[goods[j]])
                    cnt++;
                if (vis[goods[j]]&&goods[j]==products[i])
                {
                    printf("%02d -> %02d\n", goods[j], goods[j]);
                    vis[goods[j]] = 0;
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                if(cnt==1)
                {
                    for (int j = 0; j < goods.size(); j++)
                    {
                        if(vis[goods[j]])
                        {
                            printf("%02d -> %02d\n", goods[j], products[i]);
                            break;
                        }
                    }
                }
                // else
                //     printf("\n"); 
            }
        }
        else
        {
            sort(ans.begin(), ans.end(), cmp);
            node t = ans[0];
            for (int j = 0; j < t.rea.size(); j++)
            {
                vis[t.rea[j]] = 0;
                printf("%02d", t.rea[j]);
                if (j != t.rea.size() - 1)
                    printf(" + ");
            }
            printf(" -> %02d\n", t.pro);
        }
    }
    return 0;
}
// 02 + 03 + 05 -> 08
// 01 + 09 + 16 -> 03
// 04 -> 04
// 02 + 03 + 05 -> 08
// 01 + 09 + 16 -> 03
// 04 -> 04