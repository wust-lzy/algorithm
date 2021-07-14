#include <bits/stdc++.h>
#include <set>
using namespace std;

class TimeMap
{
public:
    typedef pair<int, string> pis;
    unordered_map<string, vector<pis>> m;
    /** Initialize your data structure here. */
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        vector<pis> &pairs = m[key];
        int n = pairs.size();
        if (pairs.empty())
            return "";
        pis p = {timestamp, string({127})};
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        return (i - 1)->second;
    }

    int vis[26];
    int countPalindromicSubsequence(string s)
    {
        int n = s.size();
        set<string> S;
        for (int i = 0; i < n - 2; i++)
        {
            memset(vis, -1, sizeof vis);
            for (int j = i; j < n; j++)
            {
                int x = s[j] - 'a';
                if (vis[x] == -1)
                    vis[x] = j;
                if (j - vis[x] >= 2)
                    for (int k = j - 1; k > vis[x]; k--)
                    {

                            string temp(1,s[j]);
                            temp += s[k];
                            temp += s[j];
                            S.insert(temp);
                            cout << temp << endl;

                    }
            }
        }
        return S.size();
    }
};