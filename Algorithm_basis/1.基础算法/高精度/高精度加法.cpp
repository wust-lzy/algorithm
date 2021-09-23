#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

vector<int>add(vector<int>&a,vector<int>&b)//y总板子
{
    vector<int> ans;
    int t = 0;  //进位
    for (int i = 0; i < a.size() || i < b.size(); i++)
    {
        if(i<a.size())
            t += a[i];
        if (i < b.size())
            t += b[i];
        ans.push_back(t % 10);//只加个位的
        t /= 10;
    }
    if(t)//看最后一位是否大于0
        ans.push_back(t);
    reverse(ans.begin(), ans.end());
    return ans;
}

string add(string &a,string &b){
    int i = a.length() - 1, j = b.length() - 1, add = 0;
    string ans;
    while(i>=0||j>=0||add!=0){
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;
        add += x + y;
        ans += '0' + add % 10;
        add /= 10;
    }
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
    vector<int> ans = add(a, b);
    for (int i = 0; i < ans.size();i++)
        cout << ans[i] << ' ';
    return 0;
}