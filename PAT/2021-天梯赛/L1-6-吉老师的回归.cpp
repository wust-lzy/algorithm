#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, mm;
    cin >> n >> mm;
    m = mm;
    char c = getchar();
    string s, ans;
    int cnt = 0;
    bool flag = 1;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        auto it2 = s.find("qiandao");
        auto it1 = s.find("easy");
        if (it1!=-1||it2!=-1)
            cnt++;
        else
        {
            if (m > 0)
            {
                cnt++;
                m--;
            }
            else
            {
                if (flag)
                {
                    ans = s;
                    flag = 0;
                }
            }
        }
    }
    if (mm == n)
    {
        cout << "Wo AK le";
        return 0;
    }
    if (!flag)
    {
        cout << ans;
        return 0;
    }
    cout << "Wo AK le";
    return 0;
}
