#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 10;

int main()
{
    int n;
    cin >> n;
    vector<pii> p;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        p.emplace_back(pii(a, b));
    }
    sort(p.begin(), p.end(), [](pii &a, pii &b) 
         { return a.second < b.second; });//右端点从小到大排序
    vector<int> ans;
    ans.push_back(p[0].second);
    for (int i = 1; i < p.size();i++)
    {
        bool flag = false;
        for (int j = 0; j < ans.size();j++)
        {
            if(p[i].first>ans[j])
            {
                flag = true;
                ans[j] = p[i].second;
                break;
            }
        }
        if(!flag)
            ans.push_back(p[i].second);
    }
    cout << ans.size();
    return 0;
}