#include<iostream>
#include<vector>
#include<algorithm>
#define pi pair<int,int> 

using namespace std;

void merge_section(vector<pi>&p){
    vector<pi> ans;
    sort(p.begin(), p.end());//左端点从小到大排序
    int st = -2e9, ed = -2e9;
    for(pi e:p){
        if(ed<e.first){
            if(st!=-2e9)
                ans.push_back({st, ed});
            st = e.first, ed = e.second;
        }
        else
            ed = max(ed, e.second);
    }
    if(st!=-2e9)
        ans.push_back({st, ed});
    p = ans;
}
int main()
{
    int t;
    cin >> t;
    vector<pi> p;
    while(t--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        p.push_back(pi(l, r));
    }
    merge_section(p);
    cout << p.size();
    return 0;
}