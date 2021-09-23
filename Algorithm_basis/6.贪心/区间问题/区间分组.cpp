#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
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
    sort(p.begin(), p.end());   //左端点从小到大排序
    priority_queue<int, vector<int>, greater<int>> q;//小根堆
    for (int i = 0; i < n; i++)
    {
        if(q.empty()||q.top()>=p[i].first)//新的区间无法插入最短区间的后面
            q.push(p[i].second);    //新开一个组
        else{
            q.pop();
            q.push(p[i].second);//插到最短区间的后面
        }
    }
    cout << q.size();
    return 0;
}