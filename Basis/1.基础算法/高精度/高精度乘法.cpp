#include <bits/stdc++.h>
using namespace std;

vector<int>mul(vector<int>&a,int b)//y总
{
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < a.size() || t;i++)
    {
        if(i<a.size())
            t += a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while(ans.size()>1&&ans.back()==0)
        ans.pop_back();
    return ans;
}
string multiply(string a, string b) {
    if(a=="0"||b=="0")
        return "0";
    int n = a.length(), m = b.length();
    int ans[n + m];
    fill(ans, ans + n + m, 0);
    for (int i = n - 1; i >= 0;i--)
    {
        int x = a[i] - '0';
        for (int j = m - 1; j >= 0;j--){
            int y = b[j] - '0';
            ans[i + j + 1] += x * y;
        }
    }
    for (int i = m + n - 1; i > 0;i--)
    {
        ans[i-1]+=ans[i]/10;
        ans[i] %= 10;
    }
    int idx = ans[0] == 0 ? 1 : 0;
    string res = "";
    while(idx<m+n)
        res += ans[idx++]+'0';
    return res;
}

int main()
{

    return 0;
}