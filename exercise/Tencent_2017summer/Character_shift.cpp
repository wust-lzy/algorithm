#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    while (cin >> s)
    {
        vector<char> v;
        for (int i = 0; i < s.length();i++)
        {
            if(isupper(s[i]))
                v.push_back(s[i]);
            else
                cout << s[i];
        }
        for (auto it = v.begin(); it != v.end();it++)
            cout << *it;
        cout << endl;
    }
        return 0;
}