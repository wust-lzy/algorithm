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
    int cnt = 0, ed = -2e9;
    for(const pii&e:p)
    {
        if(e.first>ed)//当前区间没有覆盖，则更新
        {
            cnt++;
            ed = e.second;
        }
    }
    cout << cnt;
    return 0;
}