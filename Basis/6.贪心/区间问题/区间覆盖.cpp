#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

#define pii pair<int,int>
int st, ed, n;

int main()
{
    scanf("%d %d", &st, &ed);
    scanf("%d", &n);
    vector<pii> p;
    for (int i = 0; i < n;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        p.emplace_back(pii(a, b));
    }
    sort(p.begin(), p.end());//按照左端点从小到大排序
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n;i++)//在左端点都<=st得情况下，选右端点最大的区间
    {
        int j = i, r = -2e9;
        while(j<n&&p[j].first<=st)
        {
            r = max(r, p[j].second);
            j++;
        }
        if(r<st)
            break;
        ans++;
        if(r>=ed)   //将st更新成右端点的最大值
        {
            flag = true;
            break;
        }
        st = r;
        i = j - 1;
    }
    if(!flag)
        cout << -1;
    else
        cout << ans;

    return 0;
}