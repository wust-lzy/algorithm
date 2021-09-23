#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
//判断a>=b?
bool cmp(vector<int>&a,vector<int>&b)
{
    if(a.size()!=b.size())
        return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0;i--)
        if(a[i]!=b[i])
            return a[i] > b[i];
    return true;
}
vector<int>sub(vector<int>&a,vector<int>&b)
{
    vector<int> ans;
    for (int i = 0, t = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if(i<b.size())
            t -= b[i];
        ans.push_back((t + 10) % 10);
        if(t<0)
            t = 1;
        else
            t = 0;
    }
    while(ans.size()>1&&ans.back()==0)//去掉前导0
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a, b;
    for (int i = s1.size() - 1; i >= 0;i--)
        a.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0;i--)
        b.push_back(s2[i] - '0');
    if(!cmp(a,b))
    {
        swap(a, b);
        cout << "-";
    }
    vector<int> ans = sub(a, b);
    for (int i = 0; i < ans.size();i++)
        cout << ans[i];
    return 0;
}