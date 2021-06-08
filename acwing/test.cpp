#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node //空闲服务器
{
    int idx, w, times;
    bool operator<(const node &p) const
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
            heap.push({temp.idx, temp.w, temp.times});
            wait.pop();
        }
        if (!heap.empty())
        {
            node temp = heap.top();
            heap.pop();
            ans.push_back(temp.idx);
            wait.push({temp.idx, temp.w, i + tasks[i]});
        }
        else
        {
            node temp = wait.top();
            wait.pop();
            ans.push_back(temp.idx);
            wait.push({temp.idx, temp.w, temp.times + tasks[i]});
        }
    }
    return ans;
}

string printMinNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), [](int &a, int &b)
         { return to_string(a) + to_string(b) < to_string(b) + to_string(a); });
    string ans = "";
    for (int e : nums)
    {
        ans += to_string(e);
    }
    return ans;
}

int func(int l, int r, vector<int> &a)
{
    if (l >= r)
        return 0;
    int mid = l + r >> 1;
    int ans = func(l, mid, a) + func(mid + 1, r, a);
    vector<int> temp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
        {
            ans += mid - i + 1;
            temp.push_back(a[j++]);
        }
    }
    while (i <= mid)
        temp.push_back(a[i++]);
    while (j <= r)
        temp.push_back(a[j++]);
    i = l;
    for (int e : temp)
        a[i++] = e;
    return ans;
}
int inversePairs(vector<int> &nums)
{
    return func(0, nums.size() - 1, nums);
}

int getMissingNumber(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (nums[mid] != mid)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int getNumberSameAsIndex(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (mid == nums[mid])
            return mid;
        if (mid > nums[mid])
            l = mid + 1;
        else
            r = mid;
    }
    return -1;
}

vector<int> findNumsAppearOnce(vector<int> &nums)
{
    int sum = 0;
    for (int x : nums) //结果为x^y
        sum ^= x;
    int X = 0;
    int k = 0;
    while (!(sum >> k & 1)) //假设x第k为为1
        k++;
    for (int e : nums) //得到k位为1的所有集合
        if (e >> k & 1)
            X ^= e;
    return {X, sum ^ X}; //x^y^x  得到y
}

void func(vector<vector<int>> &a)
{
    int n = a.size();
    vector<vector<int>> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i].push_back(a[i][j]);
        }
    }
    a = ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j];
        cout << endl;
    }
}
bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
{
    int n = mat.size();
    if (n != target.size())
        return false;
    if (mat == target)
        return true;
    for (int i = 0; i < 3; i++)
    {
        func(mat);
        if (mat == target)
            return true;
    }
    return false;
}

int reductionOperations(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> cnt(n + 1);
    int idx = 0, val = nums[0];
    for (int e : nums)
    {
        if (val == e)
            cnt[idx]++;
        else
        {
            cnt[++idx]++;
            val = e;
        }
    }
    if (idx == 0)
        return 0;
    cout << idx << endl;
    for (int i = 0; i <= idx; i++)
        cout << cnt[i] << " ";
    cout << endl;
    int ans = 0;
    for (int i = idx; i >= 0; i--)
    {
        cnt[i] += cnt[i + 1];
    }
    for (int i = 0; i <= idx; i++)
        cout << cnt[i] << " ";
    for (int i = 1; i <= idx; i++)
        ans += cnt[i];
    return ans;
}

int minFlips(string s)
{
    int n = s.length();
    if (n == 1)
        return 0;
    bool flag = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return 0;
    if (n > 2)
    {
        while (s[0] == s[1] )
        {
            char t = s[0];
            s = s.substr(1) + t;
        }
    }
    int ans1 = 0, ans2 = 0 ;
    for (int i = 0; i < n; i++)
    {
        if ((i % 2) && s[i] == '1' || !(i % 2) && s[i] == '0')
            ans1++;
        if ((i % 2) && s[i] == '0' || !(i % 2) && s[i] == '1')
            ans2++;
    }
    return  min(ans1, ans2);
}

vector<vector<int> > findContinuousSequence(int sum) {
    vector<vector<int>> ans;
    int tempsum = 0;
    for (int i = 1, j = 1; j < sum;j++)
    {
        tempsum += j;
        while(tempsum>sum)
            tempsum -= i++;
        if(tempsum==sum)
        {
            vector<int> temp;
            for (int k = i; k <= j;k++)
                temp.push_back(k);
            ans.push_back(temp);
        }
    }
    return ans;
}

vector<int> maxInWindows(vector<int>& nums, int k) {
    vector<int> ans;
    priority_queue<int> q;
    for (int i = 0; i < k;i++)
        q.push(nums[i]);
    for (int i = k; i < nums.size();i++)

        return ans;
}

vector<int> numberOfDice(int n) {
    vector<int> ans;
    const int N = 6 * n+20;
    int dp[N];
    dp[n+10] = 1;
}