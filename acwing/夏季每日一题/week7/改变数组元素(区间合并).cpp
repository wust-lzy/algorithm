#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N = 2e5 + 10;
typedef pair<int, int> pii;
void merge_section(vector<pii>&p)//合并区间算法
{
    vector<pii> ans;
    sort(p.begin(), p.end());
    int st = -2e9, ed = -2e9;
    for(pii &e:p){
        if(ed<e.first){
            if(st!=-2e9)
                ans.emplace_back(pii(st, ed));
            st = e.first, ed = e.second;
        }else
            ed = max(ed, e.second);
    }
    if(st!=-2e9)
        ans.emplace_back(pii(st, ed));
    p = ans;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int a[n] = {0};
        vector<pii> ans;
        int x;
        for (int i = 0; i < n;i++){
            scanf("%d", &x);
            if(x)
            {
                x = min(x, i + 1);//防止爆满
                ans.emplace_back(pii(i + 1 - x, i));//压入一个全是1的区间
            }
        }
        merge_section(ans);//合并区间
        for(pii &p:ans)
        {
            for (int i = p.first; i <= p.second;i++)//将区间的数置为1
                a[i] = 1;
        }
        for (int i = 0; i < n;i++)
            printf("%d ", a[i]);
        puts("");
    }
    return 0;
}