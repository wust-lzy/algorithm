#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node //空闲服务器
{
    int idx, w, times;
    bool operator<(const node &p)const
    {
        if (times != p.times)
            return times > p.times;
        if (w != p.w)
            return w > p.w;
        return idx > p.idx;
    }
};
vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
{
    int n = servers.size(), m = tasks.size();
    priority_queue<node> heap; //空闲
    priority_queue<node> wait; //等待服务器
    for (int i = 0; i < n; i++)
        heap.push({i, servers[i], 0});

    vector<int> ans;

    for (int i = 0; i < m; i++)
    {                                                  //每项任务
        while (!wait.empty() && wait.top().times <= i) //已经空闲的服务器加入空闲堆
        {
            node temp = wait.top();
            heap.push({temp.idx,temp.w,temp.times});
            wait.pop();
        }
        if (!heap.empty()){
            node temp = heap.top();
            heap.pop();
            ans.push_back(temp.idx);
            wait.push({temp.idx, temp.w, i + tasks[i]});
        }else{
            node temp = wait.top();
            wait.pop();
            ans.push_back(temp.idx);
            wait.push({temp.idx, temp.w, temp.times + tasks[i]});
        }
    }
    return ans;
}

string printMinNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int &a, int &b)
            {
              return to_string(a) + to_string(b) < to_string(b) + to_string(a);
            }
        );
    string ans = "";
    for(int e:nums){
        ans += to_string(e);
    }
    return ans;
}

int func(int l,int r,vector<int>&a){
    if(l>=r)
        return 0;
    int mid = l + r >> 1;
    int ans = func(l, mid,a) + func(mid + 1, r,a);
    vector<int> temp;
    int i = l, j = mid + 1;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j])
            temp.push_back(a[i++]);
        else{
            ans += mid - i + 1;
            temp.push_back(a[j++]);
        }
    }
    while(i<=mid)
        temp.push_back(a[i++]);
    while(j<=r)
        temp.push_back(a[j++]);
    i = l;
    for(int e:temp)
        a[i++] = e;
    return ans;
}
int inversePairs(vector<int>& nums) {
    return func(0, nums.size() - 1,nums);
}