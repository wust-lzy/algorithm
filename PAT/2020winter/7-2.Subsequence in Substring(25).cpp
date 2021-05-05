#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s, p,ans;
    cin >> s >> p;
    if(p.length()==1)
    {
        cout << p;
        return 0;
    }
    char c = p[0];
    int len = p.length(),min_len=1e9;
    for (int i = 0; i <= s.length()-len;i++)
    {
        if(s[i]==c)
        {
            int x = i+1, y = 1;
            while (y<len&&x<s.length())
            {
                if(s[x]==p[y])
                {
                    y++;
                }
                x++;
            }
            if(y!=len)
                break;
            int temp = x - i;
            if(min_len>temp)
            {
                ans = s.substr(i, temp);
                min_len = temp;
            }
        }
    }
    cout << ans;
    return 0;
}